enum cutom_keycodes {
    FEN_AE = SAFE_RANGE,
    FEN_UE,
    FEN_OE,
    FEN_SZ,
    FEN_EUR
};

enum layers {
    _COLEMAKDH = 0,
    _NUMBERS,
    _NAVIGATION,
    _SYMBOL,
    _UMLAUT
};


// Aliases for readability

#define COLEMAK  TO(_COLEMAKDH)        // Default

#define MO_UML   MO(_UMLAUT)            // Switch while held
#define MO_SYM   MO(_SYMBOL)            

#define TO_NAV   TO(_NAVIGATION)        // Switch
#define TO_NUM   TO(_NUMBERS)

#define BACKSP   MT(MOD_LCTL, KC_BSPC)  //Mod Tap Modifier when held, key when tapped
#define TAB      MT(MOD_LALT, KC_TAB)
#define MOD_A    MT(MOD_LGUI, KC_A)
#define MOD_R    MT(MOD_LALT, KC_R)
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)


#define OS_SFT   OSM(MOD_LSFT)          //OneShotModifier Tap to modify next key. Holding works too
#define OS_ALT   OSM(MOD_LALT)



// Tap Dance

enum {
    TD_NUM_SYM,
    TD_NAV_UML,
};

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
} td_tap_t;


// Function associated with all tap dances
td_state_t cur_dance_tap_hold(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void nav_uml_finished(qk_tap_dance_state_t *state, void *user_data);
void num_sim_reset(qk_tap_dance_state_t *state, void *user_data);

// Functions associated with individual tap dances
void num_sim_finished(qk_tap_dance_state_t *state, void *user_data);
void nav_uml_reset(qk_tap_dance_state_t *state, void *user_data);