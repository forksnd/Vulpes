/*
 * Vulpes (c) 2019 gbMichelle
 *
 * This program is free software under the GNU General Public License v3.0 or later. See LICENSE for more information.
 */

#pragma once
#include "../event.hpp"

DEFINE_EVENT_HOOK(EVENT_PRE_MAP_LOAD, void, char*);
DEFINE_EVENT_HOOK(EVENT_MAP_LOAD, void, char*);

DEFINE_EVENT_HOOK(EVENT_PRE_MAP_LOAD_MP, void, char*);
DEFINE_EVENT_HOOK(EVENT_MAP_LOAD_MP, void, char*);

DEFINE_EVENT_HOOK(EVENT_PRE_MAP_LOAD_SP_UI, void, char*);
DEFINE_EVENT_HOOK(EVENT_MAP_LOAD_SP_UI, void, char*);

void init_map_hooks(bool is_server);
void revert_map_hooks();