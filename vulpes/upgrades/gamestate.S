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

.intel_syntax noprefix

.globl _gamestate_table_new_wrapper
_gamestate_table_new_wrapper:
        movsx eax, bx
        jmp _gamestate_table_new_replacement


.globl _gamestate_read_from_main_file_hook_wrapper
_gamestate_read_from_main_file_hook_wrapper:
        pushad
        call _gamestate_read_from_main_file_hook
        popad
        mov al, 1
        pop ebx
        pop ecx
        ret


.globl _gamestate_read_from_profile_file_hook_wrapper
_gamestate_read_from_profile_file_hook_wrapper:
        add esp, 0x104
        pushad
        call _gamestate_read_from_profile_file_hook
        popad
        ret


.globl _gamestate_write_to_files_hook_wrapper
_gamestate_write_to_files_hook_wrapper:
        test esi, esi
        setz al
        pushad
        call _gamestate_write_to_files_hook
        popad
        ret


.globl _gamestate_copy_checkpoint_file_wrapper
_gamestate_copy_checkpoint_file_wrapper:
        mov eax, edi
        mov edx, esi
        jmp _gamestate_copy_checkpoint_file_hook


.globl _gamestate_copy_checkpoint_file
_gamestate_copy_checkpoint_file:
        mov edi, eax
        mov esi, edx
        sub esp, 0x240
        jmp [_gamestate_copy_checkpoint_file_continue_ptr]
