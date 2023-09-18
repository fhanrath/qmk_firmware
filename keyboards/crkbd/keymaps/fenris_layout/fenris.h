enum cutom_keycodes {
    FEN_KILL = SAFE_RANGE
};

enum layers {
    _COLEMAKDH = 0,
    _NUMBERS,
    _NAVIGATION,
    _SYMBOL,
    _UMLAUT,
    _SPECIAL
};


// Aliases for readability

#define COLEMAK  TO(_COLEMAKDH)        // Default
#define SPECIAL  MO(_SPECIAL)

#define MO_UML   MO(_UMLAUT)            // Switch while held
#define MO_SYM   MO(_SYMBOL)            

#define TO_NAV   TO(_NAVIGATION)        // Switch
#define TO_NUM   TO(_NUMBERS)

#define BACKSP   MT(MOD_LCTL, KC_BSPC)  //Modifier when held, key when tapped
#define MOD_A    MT(MOD_LGUI, KC_A)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_ESC  MT(MOD_LSFT, KC_ESC)


#define OS_LSFT  OSM(MOD_LSFT)          //OneShotModifier Tap to modify next key. Holding works too
#define OS_RSFT  OSM(MOD_RSFT)
#define OS_ALT   OSM(MOD_LALT)

#define UML_A RALT(KC_Q)
#define UML_S RALT(KC_S)
#define UML_U RALT(KC_Y)
#define UML_O RALT(KC_P)

#define SPC_E RALT(KC_5)

#define WM_UP LGUI(KC_UP)
#define WM_DOWN LGUI(KC_DOWN)
#define WM_LEFT LGUI(KC_LEFT)
#define WM_RIGHT LGUI(KC_RGHT)

#define WM_1 LGUI(KC_1)
#define WM_2 LGUI(KC_2)
#define WM_3 LGUI(KC_3)
#define WM_4 LGUI(KC_4)
#define WM_5 LGUI(KC_5)
#define WM_6 LGUI(KC_6)
#define WM_7 LGUI(KC_7)
#define WM_8 LGUI(KC_8)
#define WM_9 LGUI(KC_9)
#define WM_0 LGUI(KC_0)

#define WM_LAUN LGUI(KC_D)
#define WM_FSCR LGUI(KC_F)


// Tap Dance

enum {
    TD_NUM_SYM,
    TD_NAV_UML
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_TAP_INTERRUPT,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;


// Function associated with all tap dances
td_state_t cur_dance_tap_hold(tap_dance_state_t *state);

// Functions associated with individual tap dances
void nav_uml_finished(tap_dance_state_t *state, void *user_data);
void nav_uml_reset(tap_dance_state_t *state, void *user_data);

// Functions associated with individual tap dances
void num_sim_finished(tap_dance_state_t *state, void *user_data);
void num_sim_reset(tap_dance_state_t *state, void *user_data);
