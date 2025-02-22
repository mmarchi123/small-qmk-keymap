#include QMK_KEYBOARD_H
#include "features/select_word.h"

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    NAV2,
    EDIT,
    FUN,
    SYS,
};

// define one alias per key to use on the base layer, this is a
// useful level of abstraction in order to define combos
#define CK_1 KC_L
#define CK_2 KC_D
#define CK_3 KC_M
#define CK_4 MT(MOD_LSFT, KC_H)
#define CK_5 LT(SYM, KC_R)
#define CK_6 LT(NUM, KC_T)
#define CK_7 LT(NAV, KC_S)
#define CK_8 KC_G
#define CK_9 MT(MOD_LCTL, KC_TAB)
#define CK_10 MT(MOD_LALT, KC_QUOT)
#define CK_11 MT(MOD_LGUI, KC_C)
#define CK_12 MO(EDIT)
#define CK_13 LT(FUN, KC_SPC)
#define CK_14 KC_F
#define CK_15 KC_O
#define CK_16 KC_U
#define CK_17 KC_Y
#define CK_18 KC_N
#define CK_19 LT(NUM, KC_A)
#define CK_20 LT(SYM, KC_E)
#define CK_21 MT(MOD_LSFT, KC_I)
#define CK_22 MT(MOD_LGUI, KC_P)
#define CK_23 MT(MOD_LALT, KC_COMM)
#define CK_24 MT(MOD_LCTL, KC_DOT)
#define CK_25 LT(SYS, KC_BSPC)
#define CK_26 LT(SYM, KC_ENT)
#define KC_EURO LSFT(LALT(KC_2))

enum custom_keycodes {
    C_KC_ARROW = SAFE_RANGE,
    SELWBAK,
    SELWFWD,
    SELLINE,
    // macros invoked from magic combo
    M_UPDIR,
    M_ION,
    M_MENT,
    M_ENT,
    M_OU,
    M_ECAUSE,
    M_ON,
    M_UST,
    M_ER,
    M_HICH,
    M_BUT,
    M_ETURN,
    M_UEN,
    M_MPORT,
    M_LASS,
    M_EF,
    M_NT,
    M_IAM,
};

// need to be included after custom keycode definition in order to use the
// keycodes in combos.def
#include "g/keymap_combo.h"

// base
#define  ___BASE_L1___  CK_1,   CK_2,   CK_3
#define  ___BASE_R1___  CK_14,  CK_15,  CK_16
#define  ___BASE_L2___  CK_4,   CK_5,   CK_6,   CK_7,   CK_8
#define  ___BASE_R2___  CK_17,  CK_18,  CK_19,  CK_20,  CK_21
#define  ___BASE_L3___  CK_9,   CK_10,  CK_11
#define  ___BASE_R3___  CK_22,  CK_23,  CK_24
#define  ___BASE_L4___  CK_12,  CK_13
#define  ___BASE_R4___  CK_25,  CK_26

// num
#define  ___NUM__L1___  KC_7,     KC_8,   KC_9
#define  ___NUM__R1___  KC_7,     KC_8,   KC_9
#define  ___NUM__L2___  KC_0,     KC_4,   KC_5,  KC_6,  KC_NO
#define  ___NUM__R2___  KC_NO,    KC_4,   KC_5,  KC_6,  KC_0
#define  ___NUM__L3___  KC_1,     KC_2,   KC_3
#define  ___NUM__R3___  KC_1,     KC_2,   KC_3
#define  ___NUM__L4___  KC_TRNS,  KC_SPC
#define  ___NUM__R4___  KC_BSPC,  KC_DEL

// sym
#define  ___SYM__L1___  KC_AT,        S(KC_3),      S(KC_4)
#define  ___SYM__R1___  KC_BSLS,      KC_SLASH,     S(KC_SLASH)
#define  ___SYM__L2___  S(KC_8),      S(KC_EQUAL),  KC_EQUAL,    S(KC_QUOTE),  S(KC_5)
#define  ___SYM__R2___  S(KC_1),      S(KC_SCLN),   RALT(KC_3),  S(KC_GRAVE),  S(KC_BSLS)
#define  ___SYM__L3___  KC_MINUS,     S(KC_7),      KC_GRAVE
#define  ___SYM__R3___  S(KC_COMMA),  S(KC_DOT),    C_KC_ARROW
#define  ___SYM__L4___  KC_TRNS,      KC_TRNS
#define  ___SYM__R4___  KC_TRNS,      KC_TRNS

// nav
#define  ___NAV__L1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV__R1___  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS
#define  ___NAV__L2___  KC_TRNS,     KC_TRNS,     MO(NAV2),  KC_TRNS,   KC_TRNS
#define  ___NAV__R2___  KC_LEFT,     KC_DOWN,     KC_UP,     KC_RIGHT,  KC_TRNS
#define  ___NAV__L3___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV__R3___  KC_LBRC,     KC_RBRC,     KC_TRNS
#define  ___NAV__L4___  KC_TRNS,     KC_TRNS
#define  ___NAV__R4___  KC_BSPC,     KC_DEL

// nav2
#define  ___NAV2_L1___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___NAV2_R1___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___NAV2_L2___  SELWBAK,     KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS
#define  ___NAV2_R2___  A(KC_LEFT),  KC_TRNS,   KC_TRNS,  A(KC_RIGHT),  SELWFWD
#define  ___NAV2_L3___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___NAV2_R3___  SELLINE,     KC_TRNS,   KC_TRNS
#define  ___NAV2_L4___  KC_TRNS,     KC_TRNS
#define  ___NAV2_R4___  A(KC_BSPC),  A(KC_DEL)

// edit
#define  ___EDIT_L1___  SGUI(KC_G),  G(KC_F),     G(KC_G)
#define  ___EDIT_R1___  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS
#define  ___EDIT_L2___  G(KC_A),     G(KC_X),     G(KC_C),  G(KC_V),   KC_TRNS
#define  ___EDIT_R2___  KC_LEFT,     KC_DOWN,     KC_UP,    KC_RIGHT,  KC_TRNS
#define  ___EDIT_L3___  KC_TRNS,     G(KC_Z),     G(KC_Z)
#define  ___EDIT_R3___  KC_LBRC,     KC_RBRC,     KC_TRNS
#define  ___EDIT_L4___  KC_TRNS,     KC_TRNS
#define  ___EDIT_R4___  KC_BSPC,     KC_DEL

// fun
#define  ___FUN__L1___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___FUN__R1___  KC_F7,       KC_F8,     KC_F9
#define  ___FUN__L2___  KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___FUN__R2___  KC_TRNS,     KC_F4,     KC_F5,    KC_F6,    KC_TRNS
#define  ___FUN__L3___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___FUN__R3___  KC_F1,       KC_F2,     KC_F3
#define  ___FUN__L4___  KC_TRNS,     KC_TRNS
#define  ___FUN__R4___  A(KC_BSPC),  A(KC_DEL)

// sys
#define  ___SYS__L1___  KC_TRNS,         KC_BTN4,        KC_BTN5
#define  ___SYS__R1___  KC_VOLD,         KC_VOLU,        KC_MUTE
#define  ___SYS__L2___  KC_HOME,         KC_WH_R,        KC_WH_U,  KC_WH_D,  KC_WH_L
#define  ___SYS__R2___  KC_MS_L,         KC_MS_D,        KC_MS_U,  KC_MS_R,  KC_END
#define  ___SYS__L3___  MS_ACL1,         KC_BRID,        KC_BRIU
#define  ___SYS__R3___  G(KC_KP_MINUS),  G(KC_KP_PLUS),  KC_TRNS
#define  ___SYS__L4___  KC_BTN2,         KC_BTN1
#define  ___SYS__R4___  KC_TRNS,         KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_wrapper(
        ___BASE_L1___, ___BASE_R1___,
        ___BASE_L2___, ___BASE_R2___,
        ___BASE_L3___, ___BASE_R3___,
        ___BASE_L4___, ___BASE_R4___
    ),
    [NUM] = LAYOUT_wrapper(
        ___NUM__L1___, ___NUM__R1___,
        ___NUM__L2___, ___NUM__R2___,
        ___NUM__L3___, ___NUM__R3___,
        ___NUM__L4___, ___NUM__R4___
    ),
    [SYM] = LAYOUT_wrapper(
        ___SYM__L1___, ___SYM__R1___,
        ___SYM__L2___, ___SYM__R2___,
        ___SYM__L3___, ___SYM__R3___,
        ___SYM__L4___, ___SYM__R4___
    ),
    [NAV] = LAYOUT_wrapper(
        ___NAV__L1___, ___NAV__R1___,
        ___NAV__L2___, ___NAV__R2___,
        ___NAV__L3___, ___NAV__R3___,
        ___NAV__L4___, ___NAV__R4___
    ),
    [NAV2] = LAYOUT_wrapper(
        ___NAV2_L1___, ___NAV2_R1___,
        ___NAV2_L2___, ___NAV2_R2___,
        ___NAV2_L3___, ___NAV2_R3___,
        ___NAV2_L4___, ___NAV2_R4___
    ),
    [EDIT] = LAYOUT_wrapper(
        ___EDIT_L1___, ___EDIT_R1___,
        ___EDIT_L2___, ___EDIT_R2___,
        ___EDIT_L3___, ___EDIT_R3___,
        ___EDIT_L4___, ___EDIT_R4___
    ),
    [FUN] = LAYOUT_wrapper(
        ___FUN__L1___, ___FUN__R1___,
        ___FUN__L2___, ___FUN__R2___,
        ___FUN__L3___, ___FUN__R3___,
        ___FUN__L4___, ___FUN__R4___
    ),
    [SYS] = LAYOUT_wrapper(
        ___SYS__L1___, ___SYS__R1___,
        ___SYS__L2___, ___SYS__R2___,
        ___SYS__L3___, ___SYS__R3___,
        ___SYS__L4___, ___SYS__R4___
    ),
};

// clang-format off
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case CK_24: return M_UPDIR;  // . -> ..
        case CK_23: return M_BUT;    // , -> , but
        case KC_B: return M_ECAUSE;  // b -> because
        case CK_11: return M_LASS;   // c -> class
        case CK_2: return M_EF;      // d -> def
        case CK_21:
            if (mods & MOD_MASK_SHIFT) {
                return M_IAM;       // I -> I'm
            }
            return M_MPORT;         // i -> import
        case KC_J: return M_UST;    // j -> just
        case CK_3: return M_ENT;    // m -> ment
        case CK_18: return M_ION;   // n -> nion
        case CK_15: return M_NT;    // o -> o'nt
        case KC_Q: return M_UEN;    // q -> quen
        case CK_5: return M_ETURN;  // r -> return
        case CK_7: return M_ION;    // s -> sion
        case CK_6: return M_MENT;   // t -> tment
        case KC_V: return M_ER;     // v -> ver
        case KC_W: return M_HICH;   // w -> which
        case CK_17: return M_OU;    // y -> you
        case KC_EQL: return KC_GT;  // = -> =>
        case SELWBAK: return SELWFWD;
        case SELWFWD: return SELWBAK;
        case KC_PLUS:
        case KC_MINS:
        case KC_ASTR:
        case KC_PERC:
        case KC_PIPE:
        case KC_CIRC:
        case KC_TILD:
        case KC_EXLM:
        case KC_DLR:
        case KC_RABK:
        case KC_LPRN:
        case KC_RPRN:
        case KC_UNDS:
        case KC_COLN:
            return KC_EQL;  // append =
    }
    return KC_TRNS;
}

// clang-format off
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record)) { return false; }

    switch (keycode) {
        case SELWBAK: // backward word selection.
            if (record->event.pressed) {
                select_word_register('B');
            } else {
                select_word_unregister();
            }
            break;
        case SELWFWD: // forward word selection.
            if (record->event.pressed) {
                select_word_register('W');
            } else {
                select_word_unregister();
            }
            break;
        case SELLINE: // line selection.
            if (record->event.pressed) {
                select_word_register('L');
            } else {
                select_word_unregister();
            }
            break;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case C_KC_ARROW: SEND_STRING("->"); return false;
            case M_UPDIR: SEND_STRING("./"); break;
            case M_ION: SEND_STRING("ion"); break;
            case M_ENT: SEND_STRING("ent"); break;
            case M_UEN: SEND_STRING("uen"); break;
            case M_MENT: SEND_STRING("ment"); break;
            case M_OU: SEND_STRING("ou"); break;
            case M_ON: SEND_STRING("on"); break;
            case M_ECAUSE: SEND_STRING("ecause"); break;
            case M_NT: SEND_STRING("n't"); break;
            case M_IAM: SEND_STRING("'m"); break;
            case M_UST: SEND_STRING("ust"); break;
            case M_ER: SEND_STRING("er"); break;
            case M_HICH: SEND_STRING("hich"); break;
            case M_BUT: SEND_STRING(" but"); break;
            case M_ETURN: SEND_STRING("eturn"); break;
            case M_MPORT: SEND_STRING("mport"); break;
            case M_LASS: SEND_STRING("lass"); break;
            case M_EF: SEND_STRING("ef"); break;
        }
    }
    return true;
}

// rgb light

const rgblight_segment_t PROGMEM capslock_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(capslock_layer, osm_shift_layer);
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

// light up led in red when caps lock in on
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// light up led in yellow when sticky shift is activated
void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        rgblight_set_layer_state(1, true);
    }
    if (!mods) {
        rgblight_set_layer_state(1, false);
    }
}
