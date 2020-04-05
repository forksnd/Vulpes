/*
 * Vulpes (c) 2019 gbMichelle
 *
 * This program is free software under the GNU General Public License v3.0 or later. See LICENSE for more information.
 */

#pragma once

#include <vulpes/memory/types.hpp>

#pragma pack(push, 1)

class Table {
public:

    /*
    Checks if there is an empty entry and sets one up if there is,
    returns a MemRef to the allocated id.
    */
    MemRef allocate();
    /*
    Deletes the entry at the given MemRef.
    Returns true if succesful, false if it couldn't find it.
    */
    bool remove(MemRef id);

    /* Count the number of valid elements in this table.*/
    size_t count();

    char name[0x20];
    int16_t max_elements;
    int16_t element_size;
    bool is_valid;
    bool id_zero_valid;
    PAD(2);
    int32_t sig; // "d@t@"
    int16_t next_id; // Next index to use when creating a new element
    int16_t last_id; // Last used id
    MemRef next_data; // Next id value to use
}; static_assert(sizeof(Table) == 0x34);

class GenericTable : public Table {
public:
    union {
        // This union allows us to remove a bunch of reinterpret_casts.
        void* first;
        uintptr_t first_int;
    };

    /* Initializes the table the way Halo normally does it
       Never execute after the game has loaded.
    */
    void init(const char* name, uint16_t e_max, uint16_t e_size, void* array);
    void init(const char* name, uint16_t e_max, uint16_t e_size, uintptr_t array);
};

#pragma pack(pop)
