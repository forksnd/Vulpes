/*
 * This file is part of Vulpes, an extension of Halo Custom Edition's capabilities.
 * Copyright (C) 2019-2020 gbMichelle (Michelle van der Graaf)
 *
 * Vulpes is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * Vulpes is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * long with Vulpes.  If not, see <https://www.gnu.org/licenses/agpl-3.0.en.html>
 */

#pragma once

#include <vulpes/event.hpp>

DEFINE_EVENT_HOOK(EVENT_PRE_MAP_LOAD, void);
DEFINE_EVENT_HOOK(EVENT_MAP_LOAD, void);

DEFINE_EVENT_HOOK(EVENT_PRE_MAP_LOAD_MP, void);
DEFINE_EVENT_HOOK(EVENT_MAP_LOAD_MP, void);

DEFINE_EVENT_HOOK(EVENT_PRE_MAP_LOAD_SP_UI, void);
DEFINE_EVENT_HOOK(EVENT_MAP_LOAD_SP_UI, void);

void init_map_hooks(bool is_server);
void revert_map_hooks();
