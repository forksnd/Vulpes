/*
 * Vulpes (c) 2019 gbMichelle
 *
 * This program is free software under the GNU General Public License v3.0 or later. See LICENSE for more information.
 */

#include "../../hooker/hooker.hpp"
#include "../memory/types.hpp"

Signature(true, sig_message_delta_object_index, {0x8B, 0x44, 0x24, 0x14, 0x50, 0x8B, 0xCF, 0xB8, -1, -1, -1, -1, 0xE8});

Signature(true, sig_func_server_register_network_index, {0x55, 0x56, 0x8B, 0x70, 0x58, 0x8A, 0x46, 0x0C, 0x8D, 0x6E, 0x0C, 0x57, 0x83, 0xCF, 0xFF, 0x3C, 0x01, 0x75});

Signature(true, sig_func_client_register_network_index_from_remote, {0x8B, 0x40, 0x58, 0x8B, 0x50, 0x28, 0x53, 0x55, 0x8B, 0x6C, 0x24, 0x0C, 0x57, 0x8D, 0x3C, 0xAA, 0x8B, 0x17, 0x32, 0xDB, 0x83, 0xFA, 0xFF, 0x75});

Signature(true, sig_func_unregister_network_index, {0x53, 0x57, 0x8B, 0x78, 0x58, 0x8A, 0x47, 0x0C, 0x8D, 0x4F, 0x0C, 0x32, 0xDB, 0x3C, 0x01, 0x75});

Signature(true, sig_translation_table_ptr, {-1, -1, -1, -1, 0x8B, 0x52, 0x28, 0x8B, 0x34, 0x8A});

uintptr_t message_delta_object_index;
uintptr_t func_server_register_network_index;
uintptr_t func_client_register_network_index_from_remote;
uintptr_t func_unregister_network_index;

struct SyncedObjectHeader{
    uint32_t max_count;
    uint32_t int1;                  //0x4
    uint32_t int2;                  //0x8
    uint32_t initialized; //bool    //0xC

    uint32_t int4;                  //0x10
    uint32_t pointer5;              //0x14 // Can't make sense out of this
    uint32_t count;                 //0x1B
    uint32_t pointer7;              //0x1C

    uint32_t pointer8;              //0x20
    uint32_t last_used_slot;        //0x24
    MemRef* translation_index;      //0x28 // same as network_translation_table
};

SyncedObjectHeader** synced_objects_header = NULL;

int32_t server_register_network_index(MemRef object){
    SyncedObjectHeader* synced_objects = *synced_objects_header;
    if (synced_objects->count >= synced_objects->max_count){
        // Just don't even try if we're at max capacity.
        return -1;
    };
    int32_t network_id;
    asm (
        "mov eax, %[message_delta_object_index];"
        "push %[local_object_id];"
        "call %[server_register_network_index];"
        "mov %[network_id], eax;"
        "add esp, 4;"
        :
        : [message_delta_object_index] "m" (message_delta_object_index),
          [network_id] "m" (network_id),
          [local_object_id] "m" (object.raw),
          [server_register_network_index] "m" (func_server_register_network_index)
    );
    return network_id;
}

void register_network_index_from_remote(int32_t network_id, MemRef object){
    asm (
        "mov eax, %[message_delta_object_index];"
        "mov ecx, %[local_object_id];"
        "push %[network_id];"
        "call %[client_register_network_index_from_remote];"
        "add esp, 4;"
        :
        : [message_delta_object_index] "m" (message_delta_object_index),
          [local_object_id] "m" (object.raw),
          [network_id] "m" (network_id),
          [client_register_network_index_from_remote] "m" (func_client_register_network_index_from_remote)
    );
}

void unregister_network_index(MemRef object){
    asm (
        "mov eax, %[message_delta_object_index];"
        "mov esi, %[local_object_id];"
        "call %[unregister_network_index];"
        :
        : [message_delta_object_index] "m" (message_delta_object_index),
          [local_object_id] "m" (object.raw),
          [unregister_network_index] "m" (func_unregister_network_index)
    );
}

MemRef get_object_from_network_index(int32_t network_id){
    SyncedObjectHeader* synced_objects = *synced_objects_header;
    return synced_objects->translation_index[network_id];
}

int32_t get_network_id_from_object(MemRef object){
    SyncedObjectHeader* synced_objects = *synced_objects_header;
    for (int i=1; i < synced_objects->max_count; i++){
        if (synced_objects->translation_index[i].raw == object.raw){
            return i;
        };
    };
    return -1;
}

void init_network_id(){
    synced_objects_header = reinterpret_cast<SyncedObjectHeader**>(*reinterpret_cast<uintptr_t**>(sig_translation_table_ptr.address()));
    message_delta_object_index = *reinterpret_cast<uintptr_t*>(sig_message_delta_object_index.address() + 8);
    func_server_register_network_index = sig_func_server_register_network_index.address();
    func_client_register_network_index_from_remote = sig_func_client_register_network_index_from_remote.address();
    func_unregister_network_index = sig_func_unregister_network_index.address();
}
