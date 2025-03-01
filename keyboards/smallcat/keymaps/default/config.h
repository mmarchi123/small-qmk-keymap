/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define EXTRA_SHORT_COMBOS
#define TAPPING_TERM 150
#define COMBO_TERM 35
#define COMBO_TERM_PER_COMBO
#define PERMISSIVE_HOLD
#define MK_COMBINED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_TIME_TO_MAX 0
#define SELECT_WORD_OS_MAC
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER

/* make use of the mounted WS2812 led from the Waveshare RP2040-zero */
#define RGBLIGHT_LED_COUNT 1
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LIMIT_VAL 1
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define WS2812_DI_PIN GP16
