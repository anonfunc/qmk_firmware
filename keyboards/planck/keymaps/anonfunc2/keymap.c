#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

#include "keymap_steno.h"

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _STENO,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Combo map diagram at end.
// Note that the combo section can be commented out and all keys should still be reachable on a layer.
enum combos {
  // Left hand
  QW_TICK,
  WF_ESC,
  XC_TAB,
  ZX_SHIFT,
  // Right hand
  HCMA_MINUS,
  DOT_CMA_QUOTE,
  UY_ENTER,
  YCLN_BSLASH,
  SLASHDOT_SPACE,
  ENTERSEMI_LEADER,
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM hcma_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM dot_cma_combo[] = {KC_DOT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ycln_combo[] = {KC_Y, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM slashdot_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
// const uint16_t PROGMEM entersemi_combo[] = {KC_SCOLON, KC_ENTER, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // Left hand
  [QW_TICK] = COMBO(qw_combo, KC_GRAVE),
  [WF_ESC] = COMBO(wf_combo, KC_ESC),
  [XC_TAB] = COMBO(xc_combo, KC_TAB),
  [ZX_SHIFT] = COMBO(zx_combo, KC_LSHIFT),

  // Right hand
  [HCMA_MINUS] = COMBO(hcma_combo, KC_MINUS),
  [DOT_CMA_QUOTE] = COMBO(dot_cma_combo, KC_QUOTE),
  [UY_ENTER] = COMBO(uy_combo, KC_ENTER),
  [YCLN_BSLASH] = COMBO(ycln_combo, KC_BSLASH),
  [SLASHDOT_SPACE] = COMBO(slashdot_combo, KC_SPACE),
  // [ENTERSEMI_LEADER] = COMBO_ACTION(entersemi_combo)
};
/* ## COMBOS
 * ## ,-------------+------+------+------.          ,------+------+-------------+------.
 * ## |  Backtick   |      |      |      |          |      |      |   Enter     |      |
 * ## |      |     Esc     |      |      |          |      |      |      |  Backslash  |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |     Tab     |      |      |          |      |      |    Quote    |      |
 * ## |    Shift    |      |      |      |          |      |    Minus    |    Space    |
 * ## `------+------+------+------+------|          +------+------+------+------+------'
 * ##               |      |      |      |          |      |      |      | 
 * ##               |      |      |      |          |      |      |      | 
 * ##               '------+------+------'          `------+------+------'
 */ 
//Tap Dance Declarations
enum {
  TD_A_ESC = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  // [TD_A_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC)
// Other declarations would go here, separated by commas, if you have them
};

// In Layer declaration, add tap dance item in place of a key code
// TD(TD_A_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Colemak-ModDH
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   Q  |   W  |   F  |   P  |   B  |          |   J  |   L  |   U  |   Y  |   ;  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |   A  |   R  |   S  |   T  |   G  |          |   K  |   N  |   E  |   I  |   O  |
 * ## |Shift | Ctrl | Alt  | Cmd  |      |          |      | Cmd  | Alt  | Ctrl |Shift |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |   Z  |   X  |   C  |   D  |   V  |          |   M  |   H  |   ,  |   .  |   /  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          |------+------+------+------+------'
 * ##               |  TAB | BKSP |L(ESC)|          |Space |Enter |   '  |
 * ##               |      |      |Lower |          |Raise |      |      |
 * ##               `------+------+------'          `------+------+------'
 * 
 * Since the board I'm moving to has no lighting, all layers *must* be hold to activate.
 */
  [_BASE] = LAYOUT_planck_grid(
    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_NO, KC_NO, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, 
    LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G, KC_NO, KC_NO, KC_K, LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), 
    KC_Z, KC_X, KC_C, KC_D, KC_V,  KC_NO, KC_NO, KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLASH,
    KC_NO, KC_NO, KC_TAB, KC_ESC, LT(_LOWER, KC_BSPACE), KC_NO, KC_NO, LT(_RAISE, KC_SPACE), KC_ENTER, KC_QUOTE, KC_NO, KC_NO
    ),

/* ## Lower
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   !  |   @  |   #  |   $  |   %  |          |   ^  |   &  |   *  |   (  |   )  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------+
 * ## |   F1 | F2   |  F3  |  F4  |  F5  |          |   \  |   -  |   +  |   [  |   ]  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------+
 * ## |   F6 |  F7  |  F8  |  F9  |  F10 |          |   |  |   _  |   =  |   {  |   }  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          |------+------+------+------+------'
 * ##               | F11  | F12  |xxxxxx|          |ADJUST|   `  |   ~  |
 * ##               |      |      |      |          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_LOWER] = LAYOUT_planck_grid(
      KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC, KC_NO, KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN,
      KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_NO,KC_NO, KC_BSLASH, LGUI_T(KC_MINUS), LALT_T(KC_EQUAL), LCTL_T(KC_LBRACKET), LSFT_T(KC_RBRACKET),
      KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_NO,KC_NO, KC_PIPE,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,
      KC_NO, KC_NO, KC_F11, KC_F12, KC_TRNS, KC_NO,KC_NO, KC_TRNS,KC_GRAVE,KC_TILDE,KC_NO,KC_NO
      ),

/* ## Raise
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   1  |   2  |   3  |   4  |   5  |          |   6  |   7  |   8  |   9  |   0  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |SHIFT |CTRL  |ALT   |CMD   | PGUP |          | whlu | left | down | up   | right|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------|------+------+------+------+
 * ## | |> ||| Vol- | Vol+ | Mute | PGDN |          | whld | mleft|mdwn  | mup  | mrght|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          |------+------+------+------+------'
 * ##               |      |      |Del   |          |xxxxxx|Click |RClick|
 * ##               |      |      |ADJUST|          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_RAISE] = LAYOUT_planck_grid(
      KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_NO, KC_NO, KC_6,   KC_7,          KC_8,            KC_9,              KC_0,
      KC_LSHIFT, KC_LCTL,KC_LALT,KC_LGUI,KC_PGUP,  KC_NO, KC_NO, KC_MS_WH_UP, KC_LEFT,  KC_DOWN,KC_UP,KC_RIGHT, 
      KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGDN,  KC_NO, KC_NO, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, 
      KC_NO, KC_NO, KC_HOME, KC_END, LT(_LOWER, KC_DELETE),       KC_NO, KC_NO, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO
      ),

/* ## Adjust (Lower and Raise)
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |      |      |      |Steno |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |Scrn  |Talon |      |          |      | IDEs |      |      |      |
 * ## |      |      |Saver |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          +------+------+------+------+------'
 * ##               |      |      |      |          |      |      |Reset |
 * ##               |      |      |      |          |      |      |      | 
 * ##               `------+------+------'          `------+------+------'
 */
  [_ADJUST] = LAYOUT_planck_grid(
      KC_NO, KC_NO, KC_NO, TO(_STENO), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, HYPR(KC_BSPACE), HYPR(KC_TAB), KC_NO, KC_NO, KC_NO, HYPR(KC_T), KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, DEBUG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO
      ),

/* ## Steno (Plover)
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |  #   |  #   |  #   |  #   |  #   |          |  #   |  #   |  #   |  #   | Exit |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |  S   |  T   |  P   |  H   |  *   |          |  F   |  P   |  L   |  T   |  D   |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |  S   |  K   |  W   |  R   |  *   |          |  R   |  B   |  G   |  S   |  Z   |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          +------+------+------+------+------'
 * ##               |  *   |  A   |  O   |          |  E   |  U   |  *   |
 * ##               |      |      |      |          |      |      |      | 
 * ##               `------+------+------'          `------+------+------'
 */
  [_STENO] = LAYOUT_planck_grid(
      STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO, KC_NO, STN_N6,  STN_N7,  STN_N8,  STN_N9,  TO(_BASE),
      STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, KC_NO, KC_NO, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
      STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_NO, KC_NO, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
      KC_NO, KC_NO, STN_ST3, STN_A,   STN_O, KC_NO, KC_NO, STN_E, STN_U, STN_ST4, KC_NO, KC_NO
      ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  rgblight_mode(1);
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

#define HSV_WHITE 0, 0, 255

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [0] = {
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE},      {HSV_WHITE},       {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}
    },
    [1] = {
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {OFF}, {OFF}, {HSV_RED}, {HSV_RED},      {HSV_RED},       {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}
    },
    [2] = {
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE},      {HSV_BLUE},       {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}
    },
    [3] = {
        {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},
        {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},
        {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},
        {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN},      {HSV_GREEN},       {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}
    },
    [4] = {
        {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {OFF}, {OFF}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {OFF}, {OFF}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {OFF}, {OFF}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {OFF}, {OFF}, {HSV_ORANGE}, {HSV_ORANGE},      {HSV_ORANGE},       {OFF}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {OFF}, {OFF}
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  // This was auto-generated.  Why a switch statement here?
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

LEADER_EXTERNS();

// void process_combo_event(uint8_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case ENTERSEMI_LEADER:
//       if (pressed) {
//         uprint("started leading combo\n");
//         qk_leader_start();
//       }
//       break;
//   }
// }

// void leader_start(void) {
//   uprint("started leading\n");
// }

// void leader_end(void) {
//   uprint("stopped leading\n");
// }

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCMD("a") SS_LCMD("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}