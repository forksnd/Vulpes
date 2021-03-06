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

enum class TagTypes {
    ACTOR                              = 0x61637472,    // actr
    ACTOR_VARIANT                      = 0x61637476,    // actv
    ACTOR_VARIANT_TRANSFORM_COLLECTION = 0x61767463,    // avtc (os)
    ACTOR_VARIANT_TRANSFORM_IN         = 0x61767469,    // avti (os)
    ACTOR_VARIANT_TRANSFORM_OUT        = 0x6176746f,    // avto (os)
    ANTENNA                            = 0x616E7421,    // ant!
    BIPED                              = 0x62697064,    // bipd
    BITMAP                             = 0x6269746d,    // bitm
    CAMERA_TRACK                       = 0x7472616b,    // trak
    COLOR_TABLE                        = 0x636f6c6f,    // colo
    CONTINUOUS_DAMAGE_EFFECT           = 0x63646d67,    // cdmg
    CONTRAIL                           = 0x636f6e74,    // cont
    DAMAGE_EFFECT                      = 0x6a707421,    // jpt!
    DECAL                              = 0x64656361,    // deca
    DETAIL_OBJECT_COLLECTION           = 0x646f6263,    // dobc
    DEVICE                             = 0x64657669,    // devi
    DEVICE_CONTROL                     = 0x6374726c,    // ctrl
    DEVICE_LIGHT_FIXTURE               = 0x6c696669,    // lifi
    DEVICE_MACHINE                     = 0x6d616368,    // mach
    DIALOGUE                           = 0x75646c67,    // udlg
    EFFECT                             = 0x65666665,    // effe
    EFFECT_POSTPROCESS                 = 0x65667070,    // efpp (os)
    EFFECT_POSTPROCESS_COLLECTION      = 0x65667063,    // efpc (os)
    EFFECT_POSTPROCESS_GENERIC         = 0x65667067,    // efpg (os)
    EQUIPMENT                          = 0x65716970,    // eqip
    EQUIPMENT_HUD_INTERFACE            = 0x65716869,    // eqhi
    FLAG                               = 0x666c6167,    // flag
    FOG                                = 0x666f6720,    //"fog "
    FONT                               = 0x666f6e74,    // font
    GARBAGE                            = 0x67617262,    // garb
    GBXMODEL                           = 0x6d6f6432,    // mod2
    GLOBALS                            = 0x6d617467,    // matg
    GLOW                               = 0x676c7721,    // glw!
    GRENADE_HUD_INTERFACE              = 0x67726869,    // grhi
    HUD_GLOBALS                        = 0x68756467,    // hudg
    HUD_MESSAGE_TEXT                   = 0x686d7420,    //"hmt "
    HUD_NUMBER                         = 0x68756423,    // hud#
    INPUT_DEVICE_DEFAULTS              = 0x64657663,    // devc
    ITEM                               = 0x6974656d,    // item
    ITEM_COLLECTION                    = 0x69746d63,    // itmc
    LENS_FLARE                         = 0x6c656e73,    // lens
    LIGHT                              = 0x6c696768,    // ligh
    LIGHT_VOLUME                       = 0x6d677332,    // mgs2
    LIGHTNING                          = 0x656c6563,    // elec
    MATERIAL_EFFECTS                   = 0x666f6f74,    // foot
    METER                              = 0x6d657472,    // metr
    MODEL                              = 0x6d6f6465,    // mode
    MODEL_ANIMATIONS                   = 0x616E7472,    // antr
    MODEL_ANIMATIONS_YELO              = 0x6d616779,    // magy (os)
    MODEL_COLLISION_GEOMETRY           = 0x636f6c6c,    // coll
    MULTILINGUAL_UNICODE_STRING_LIST   = 0x756e6963,    // unic (os)
    MULTIPLAYER_SCENARIO_DESCRIPTION   = 0x6d706c79,    // mply
    OBJECT                             = 0x6f626a65,    // obje
    PARTICLE                           = 0x70617274,    // part
    PARTICLE_SYSTEM                    = 0x7063746c,    // pctl
    PHYSICS                            = 0x70687973,    // phys
    PLACEHOLDER                        = 0x706c6163,    // plac
    POINT_PHYSISCS                     = 0x70706879,    // pphy
    PREFERENCES_NETWORK_GAME           = 0x6e677072,    // ngpr
    PROJECT_YELLOW                     = 0x79656c6f,    // yelo (os)
    PROJECT_YELLOW_GLOBALS             = 0x67656c6f,    // gelo (os)
    PROJECTILE                         = 0x70726f6a,    // proj
    SCENARIO                           = 0x73636e72,    // scnr
    SCENARIO_STRUCTURE_BSP             = 0x73627370,    // sbsp
    SCENERY                            = 0x7363656e,    // scen
    SHADER                             = 0x73686472,    // shdr
    SHADER_ENVIRONMENT                 = 0x73656e76,    // senv
    SHADER_MODEL                       = 0x736f736f,    // soso
    SHADER_POSTPROCESS                 = 0x73687070,    // shpp (os)
    SHADER_POSTPROCESS_GENERIC         = 0x73687067,    // shpg (os)
    SHADER_POSTPROCESS_GLOBALS         = 0x73707067,    // sppg (os)
    SHADER_TRANSPARENT_CHICAGO         = 0x73636869,    // schi
    SHADER_TRANSPARENT_CHICAGO_EXTENDED= 0x73636578,    // scex
    SHADER_TRANSPARENT_GENERIC         = 0x736f7472,    // sotr
    SHADER_TRANSPARENT_GLASS           = 0x73676c61,    // sgla
    SHADER_TRANSPARENT_METER           = 0x736d6574,    // smet
    SHADER_TRANSPARENT_PLASMA          = 0x73706c61,    // spla
    SHADER_TRANSPARENT_WATER           = 0x73776174,    // swat
    SKY                                = 0x736b7920,    //"sky "
    SOUND                              = 0x736e6421,    // snd!
    SOUND_ENVIRONMENT                  = 0x736e6465,    // snde
    SOUND_LOOPING                      = 0x6c736e64,    // lsnd
    SOUND_SCENERY                      = 0x73736365,    // ssce
    SPHEROID                           = 0x626f6f6d,    // boom
    STRING_ID_YELO                     = 0x73696479,    // sidy (os)
    STRING_LIST                        = 0x73747223,    // str#
    TAG_COLLECTION                     = 0x74616763,    // tagc
    TAG_DATABASE                       = 0x7461672b,    // tag+
    TEXT_VALUE_PAIR_DEFINITION         = 0x73696c79,    // sily (os)
    UI_WIDGET_COLLECTION               = 0x536f756c,    // Soul
    UI_WIDGET_DEFINITION               = 0x44654c61,    // DeLa
    UNICODE_STRING_LIST                = 0x75737472,    // ustr
    UNIT                               = 0x756e6974,    // unit
    UNIT_HUD_INTERFACE                 = 0x756e6869,    // unhi
    VEHICLE                            = 0x76656869,    // vehi
    VIRTUAL_KEYBOARD                   = 0x76636b79,    // vcky
    WEAPON                             = 0x77656170,    // weap
    WEAPON_HUD_INTERFACE               = 0x77706869,    // wphi
    WEATHER_PARTICLE_SYSTEM            = 0x7261696e,    // rain
    WIND                               = 0x77696e64,    // wind
};
