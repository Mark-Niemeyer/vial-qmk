/* Copyright 2023 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layers {
    _QWERTY = 0,
    _DVORAK,
    _COLEMAK_DH,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
    _DESPECIAL,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM       MO(_SYM)
#define NAV       MO(_NAV)
#define FKEYS     MO(_FUNCTION)
#define ADJUST    MO(_ADJUST)
#define DESPECIAL MO(_DESPECIAL)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |LShift|  |RShift|      |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |LCtrl |  | RCtrl|      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |      | LAlt |  | RAlt |      |   H  |   J  |   K  |   L  | ;  : | RShift |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  ; | . :  | -  _ | RCtrl  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_QWERTY] = LAYOUT_myr(
      KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,          KC_LSFT,     KC_RSFT,          KC_6     ,  KC_7 , KC_8 ,   KC_9   ,KC_0   , KC_DEL,
      KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,          KC_LCTL,     KC_RCTL,          KC_Y     ,  KC_U , KC_I ,   KC_O   ,KC_P   , KC_BSPC,
      KC_LSFT , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,          KC_LALT,     KC_RALT,          KC_H     ,  KC_J , KC_K ,   KC_L   ,KC_SCLN, KC_RSFT,
      KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , DE_LCBR ,KC_RALT,     FKEYS  , DE_RCBR ,KC_N     ,  KC_M , KC_COMM, KC_DOT ,KC_SLSH, KC_RCTL,
                                  ADJUST,   KC_LGUI, ALT_ENT,KC_SPC ,NAV,         SYM    , KC_SPC , DESPECIAL,KC_RGUI, KC_APP,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                            KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ),

/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |LShift|  |RShift|      |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  Tab   | ' "  | , <  | . >  |   P  |   Y  |      |LCtrl |  | RCtrl|      |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |      | LAlt |  | RAlt |      |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_DVORAK] = LAYOUT_myr(
      KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,         KC_LSFT,     KC_RSFT,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_ESC,
      KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,         KC_LCTL,     KC_RCTL,          KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_BSPC,
      CTL_ESC , KC_A ,  KC_O   ,  KC_E  ,   KC_U ,   KC_I ,         KC_LALT,     KC_RALT,          KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , CTL_MINS,
      KC_LSFT ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , KC_RSFT,
                                  ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                            KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ),

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |LShift|  |RShift|      |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |      |LCtrl |  | RCtrl|      |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |      | LAlt |  | RAlt |      |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_COLEMAK_DH] = LAYOUT_myr(
      KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,         KC_LSFT,     KC_RSFT,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_ESC,
      KC_TAB  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,         KC_LCTL,     KC_RCTL,          KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, KC_BSPC,
      CTL_ESC , KC_A ,  KC_R   ,  KC_S  ,   KC_T ,   KC_G ,         KC_LALT,     KC_RALT,          KC_M,   KC_N ,  KC_E ,   KC_I ,  KC_O , CTL_QUOT,
      KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  ADJUST, KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                            KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      | PgUp | Home |   ↑  | End  | VolUp| Delete |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |  GUI |  Alt | Ctrl | Shift|      |      |      |  |      |      | PgDn |  ←   |   ↓  |   →  | VolDn| Insert |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,----------------------------.      ,------.                 ,----------------------------.      ,------.
 * | Prev | Next | Pause | Stop |      | Mute |                 | Prev | Next | Pause | Stop |      | Mute TEAMS |
 * `----------------------------'      `------'                 `----------------------------'      '------'
 */
    [_NAV] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,          _______, _______,          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______,KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          RCS(KC_M)
    ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |    `   |  1   |  2   |  3   |  4   |  5   |      |      |  |      |      |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |      |      |  |      |      |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------'      `------'                `---------------------------'      '------'
 */
    [_SYM] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,          _______, _______,            KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,          _______, _______,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |  F9  | F10  | F11  | F12  |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |      |      |  |      |      |      | Shift| Ctrl |  Alt |  GUI |        |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------'      `------'                `---------------------------'      '------'
 */
    [_FUNCTION] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,          _______, _______,          _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |QWERTY|      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |      |      |  |      |      | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
 * |        |      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------'      `------'                `---------------------------'      '------'
 */
    [_ADJUST] = LAYOUT_myr(
      _______, _______, _______, _______, _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, QWERTY , _______, _______,         _______, _______,          _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, DVORAK , _______, _______,         _______, _______,          RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, COLEMAK, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______

    ),

// /*
//  * DE special characters - _DESPECIAL
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |   Ü  |      |   Ö  |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |  Ä   |   ß  |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
    [_DESPECIAL] = LAYOUT_myr(
      _______, _______  , _______, _______  , _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, LCA(KC_Q), _______, LCA(KC_E), _______, _______,          _______, _______,          _______, DE_UDIA, _______, DE_ODIA, _______, _______,
      _______, DE_ADIA  , DE_SS  , _______  , _______, _______,          _______, _______,          _______, DE_LABK, DE_RABK, DE_PIPE, DE_BSLS, _______,
      _______, _______  , _______, _______  , _______, _______, DE_LBRC, _______, _______, DE_RBRC, _______, DE_HASH, DE_CIRC, _______, DE_PLUS, _______,
                                   _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______

    ),

// /*
//  * Layer template - LAYOUT_myr
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *
//  * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |      |
//  * `-----------------------------'      `------'                `---------------------------'      '------'
//  */
//     [_LAYERINDEX] = LAYOUT_myr(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
bool oled_task_user(void) {
  // Your code goes here
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Your code goes here
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

// Vial-specific encoder code

#if defined(ENCODER_MAP_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
  return false;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [1] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [2] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [3] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [4] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [5] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [6] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [7] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    }
};
#endif