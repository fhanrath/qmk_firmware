enum cutom_keycodes {
    WM_KILL = SAFE_RANGE,
    WM_FLOAT,
    MAC_MUTE,
    MAC_KILL,
    MAC_FSCR,
    MAC_EUR,
    UML_A_M,
    UML_U_M,
    UML_O_M
};

enum layers {
    _COLEMAKDH = 0,
    _NUMBERS,
    _NAVIGATION,
    _SYMBOL,
    _UMLAUT,
    _WM,
    _COLEMAKDH_MAC,
    _NUMBERS_MAC,
    _NAVIGATION_MAC,
    _SYMBOL_MAC,
    _UMLAUT_MAC,
    _WM_MAC
};


// Aliases for readability

#define MO_UML   MO(_UMLAUT)            // Switch while held
#define MO_SYM   MO(_SYMBOL)
#define MO_NAV   MO(_NAVIGATION)
#define MO_NUM   MO(_NUMBERS)
#define MO_WM    MO(_WM)

#define MAC_UML   MO(_UMLAUT_MAC)
#define MAC_SYM   MO(_SYMBOL_MAC)
#define MAC_NAV   MO(_NAVIGATION_MAC)
#define MAC_NUM   MO(_NUMBERS_MAC)
#define MAC_WM    MO(_WM_MAC)

#define TO_MAC   TO(_COLEMAKDH_MAC) // TODO: implement Mac layers
#define TO_LINUX TO(_COLEMAKDH) // TODO: implement Mac layers

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
#define WM_MUTE LGUI(KC_M)

#define MAC_1 LCTL(KC_1)
#define MAC_2 LCTL(KC_2)
#define MAC_3 LCTL(KC_3)
#define MAC_4 LCTL(KC_4)
#define MAC_5 LCTL(KC_5)
#define MAC_6 LCTL(KC_6)
#define MAC_7 LCTL(KC_7)
#define MAC_8 LCTL(KC_8)
#define MAC_9 LCTL(KC_9)
#define MAC_0 LCTL(KC_0)

#define MAC_LAUN LGUI(KC_SPC)
