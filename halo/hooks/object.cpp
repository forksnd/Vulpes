/*
 * Vulpes (c) 2019 gbMichelle
 *
 * This program is free software under the GNU General Public License v3.0 or later. See LICENSE for more information.
 */

#include "../../hooker/hooker.hpp"
#include "../memory/object.hpp"

Signture(true, sig_object_update,
    {0x51, 0x8B, 0x0D, -1, -1, -1, 0x00, 0x8B, 0x51, 0x34, 0x53, 0x8B,
     0x5C, 0x24, 0x0C, 0x8B, 0xC3, 0x25, 0xFF, 0xFF, 0x00, 0x00}); // + 0 size 7

Signature(true, sig_objects_update,
    {0x00, 0x8A, -1, 0x0C, 0x83, 0xEC, 0x0C}); // -5 on client, -4 on server. size 6 on client, size 5 on server.

Signature(true, sig_object_new,
    {0x81, 0xEC, 0x1C, 0x02, 0x00, 0x00, 0x8B, 0x0D}); // size 6, do manual

Signature(true, sig_weapon_fire_call,
    {0x8B, 0x8C, 0x24, 0xAC, 0x00, 0x00, 0x00, 0x50, 0x51, 0x56,
     0xE8, -1, -1, 0x00, 0x00, 0x83, 0xC4, 0x0C}); // + 0xA size 5
Signature(true, sig_weapon_fire_object_new_call,
    {0x8D, 0x84, 0x24, 0xA4, 0x00, 0x00, 0x00, 0x50,
     0xE8, -1, -1, -1, 0x00, 0x8B, 0xF0}); // + 8 size 5

Signature(true, sig_biped_jump,
    {0x8B, 0x0D, -1, -1, -1, 0x00,
     0x8B, 0x51, 0x34, 0x83, 0xEC, 0x10, 0x53, 0x55}); // size 6 do manual


void init_object_hooks(){
}

void revert_object_hooks(){
}
