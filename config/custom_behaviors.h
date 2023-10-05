#include "./adv360pro_keypos.h"
#include "./zmk_helper.h"

/* Global settings */

#define QUICK_TAP_MS 150

&sk {  // sticky-key config
    release-after-ms = <600>;  // release after 0.6s
    quick-release;             // no double capitalization when rolling keys
};

&sl {  // sticky-layer config
    ignore-modifiers;          // allow chording sticky mods & layers
};

&lt {  // layer-tap config
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
};

/* Apple Globe key */
#define C_KEYBOARD_LAYOUT_SELECT (ZMK_HID_USAGE(HID_USAGE_CONSUMER, 0x029D))
#define GLOBE C_KEYBOARD_LAYOUT_SELECT
// As per PR 1938

/* Homerow mods */

#define KEYS_L LT0 LT1 LT2 LT3 LT4 LM0 LM1 LM2 LM3 LM4 LB0 LB1 LB2 LB3 LB4  // left hand
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4  // right hand
#define THUMBS LH2 LH1 LH0 RH0 RH1 RH2                                      // thumbs

#define MAKE_HRM(NAME, HOLD, TAP, TRIGGER_POS) \
  ZMK_BEHAVIOR(NAME, hold_tap, \
      flavor = "balanced"; \
      tapping-term-ms = <280>; \
      quick-tap-ms = <QUICK_TAP_MS>; \
      global-quick-tap-ms = <150>; \
      bindings = <HOLD>, <TAP>; \
      hold-trigger-key-positions = <TRIGGER_POS>; \
      hold-trigger-on-release; \
      )
#define MAKE_HRM_SHIFT(NAME, HOLD, TAP, TRIGGER_POS) \
  ZMK_BEHAVIOR(NAME, hold_tap, \
      flavor = "balanced"; \
      tapping-term-ms = <280>; \
      quick-tap-ms = <QUICK_TAP_MS>; \
      global-quick-tap-ms = <125>; \
      bindings = <HOLD>, <TAP>; \
      hold-trigger-key-positions = <TRIGGER_POS>; \
      hold-trigger-on-release; \
      )
MAKE_HRM(hml, &kp, &kp, KEYS_R THUMBS)  // left-hand HRMs
MAKE_HRM_SHIFT(hmls, &kp, &kp, KEYS_R THUMBS) // left-hand homerow mod for shift
MAKE_HRM(hmr, &kp, &kp, KEYS_L THUMBS)  // right-hand
MAKE_HRM_SHIFT(hmrs, &kp, &kp, KEYS_L THUMBS) // right-hand homerow mod for shift

/* Nav cluster */

// long-tap action on hold, short-tap action on all interrupts
#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <220>; \
    quick-tap-ms = <220>; \
    hold-trigger-key-positions = <0>;

&mt { MT_CORE };
ZMK_BEHAVIOR(mt_home, hold_tap, bindings = <&masked_home>, <&kp>; MT_CORE)
ZMK_BEHAVIOR(mt_end,  hold_tap,  bindings = <&masked_end>, <&kp>; MT_CORE)

#define NAV_LEFT  &mt_home 0   LEFT    // tap: left  | long-tap: beginning of line
#define NAV_RIGHT &mt_end 0    RIGHT   // tap: right | long-tap: end       of line
#define NAV_UP    &kp UP               // tap: up
#define NAV_DOWN  &kp DOWN             // tap: down
#define NAV_BSPC  &mt LA(BSPC) BSPC    // tap: bspc  | long-tap: delete word backward
#define NAV_DEL   &mt LA(DEL)  DEL     // tap: del   | long-tap: delete word forward

#define SPC_UP    &kp LA(LG(UP))
#define SPC_DOWN  &kp LA(LG(DOWN))
#define SPC_LEFT  &kp LA(LG(LEFT))
#define SPC_RIGHT &kp LA(LG(RIGHT))
#define SPC_FULL  &kp LA(LG(F))
#define SPC_MVR   &kp LC(LA(LG(RIGHT)))
#define SPC_MVL   &kp LC(LA(LG(LEFT)))
#define SPC_UNDO  &kp LC(LA(LG(Z)))


// NUM Layer Home row mods

#define NUM_LBKT   &hmr RSHFT LBKT
#define NUM_RBKT   &hmr RGUI RBKT
#define NUM_DOLLAR &hmr RALT DOLLAR
#define NUM_AT     &hmr LCTRL AT

// SYM Layer home row mods
#define SYM_FSLH   &hml LCTRL FSLH
#define SYM_LT     &hml LALT LT
#define SYM_MINUS  &hml LGUI MINUS
#define SYM_EQUAL  &hml LSHFT EQUAL

// NAV Layer Home row mods
#define PREV_WINDOW &hml LCTRL LS(LG(GRAVE))
#define NEXT_WINDOW &hml LALT LG(GRAVE)
#define NAV_STAB    &hml LGUI LS(TAB)
#define NAV_TAB     &hmls LSHFT TAB

#define DSK_PREV    &kp LC(LEFT)      // previous desktop
#define DSK_NEXT    &kp LC(RIGHT)      // next     desktop

// TODO - figure out way to get swapper on index + middle finger with home row mods
#define SWAP_PREV   &kp LS(TAB) // I'd like this to still work as a home row mod, but doesn't work with tri-state swapper
// #define SWAPPER     &hml LSHFT &swapper // This doesn't work TODO - figure out how to bind swapper into a hold-tap

// Quick Layer shortcuts
// All keys become tap: command + (key) and long tap: shift + command + (key)
#define Q_Q &mt LS(LG(Q)) LG(Q)
#define Q_W &mt LS(LG(W)) LG(W)
#define Q_F &mt LS(LG(F)) LG(F)
#define Q_P &mt LS(LG(P)) LG(P)
#define Q_B &mt LS(LG(B)) LG(B)
#define Q_A &mt LS(LG(A)) LG(A)
#define Q_R &mt LS(LG(R)) LG(R)
#define Q_S &mt LS(LG(S)) LG(S)
#define Q_T &mt LS(LG(T)) LG(T)
#define Q_G &mt LS(LG(G)) LG(G)
#define Q_Z &mt LS(LG(Z)) LG(Z)
#define Q_X &mt LS(LG(X)) LG(X)
#define Q_C &mt LS(LG(C)) LG(C)
#define Q_D &mt LS(LG(D)) LG(D)
#define Q_V &mt LS(LG(V)) LG(V)

// Right hand hyper keys
// need this to be able to preserve plain hyper modifier behavior on right hand while using left hyper key
#define Q_J &mt LS(LG(J)) LG(J)
#define Q_L &mt LS(LG(L)) LG(L)
#define Q_U &mt LS(LG(U)) LG(U)
#define Q_Y &mt LS(LG(Y)) LG(Y)
#define Q_SQT &mt LS(LG(SQT)) LG(SQT)
#define Q_M &mt LS(LG(M)) LG(M)
#define Q_N &mt LS(LG(N)) LG(N)
#define Q_E &mt LS(LG(E)) LG(E)
#define Q_I &mt LS(LG(I)) LG(I)
#define Q_O &mt LS(LG(O)) LG(O)
#define Q_K &mt LS(LG(K)) LG(K)
#define Q_H &mt LS(LG(H)) LG(H)
#define Q_COMMA &mt LS(LG(COMMA)) LG(COMMA)
#define Q_DOT &mt LS(LG(DOT)) LG(DOT)
#define Q_QMARK &mt LS(LG(QMARK)) LG(QMARK)
//
// misc aliases
#define LOCK_SCRN   &kp LC(LG(Q))
#define NUM_MULTI   &kp KP_MULTIPLY
#define CANCEL      &kp K_CANCEL             // cancel caps-word, num-word and smart-mouse
#define LHYP      LS(LC(LA(LGUI)))
#define RHYP      RS(RC(RA(RGUI)))


// mask CTRL when holding left/right to avoid accidental jumps to beginning/end of document
#define MASK_MODS(NAME, MODS, BINDING) \
    ZMK_BEHAVIOR(NAME, mod_morph, \
        bindings = <BINDING>, <BINDING>; \
        mods = <MODS>; \
    )
MASK_MODS(masked_home, (MOD_LCTL), &kp HOME)
MASK_MODS(masked_end,  (MOD_LCTL), &kp END)


// tap: sticky-shift | shift + tap/ double-tap: caps-word | hold: shift
ZMK_BEHAVIOR(smart_shft, mod_morph,
    bindings = <&sk LSHFT>, <&caps_word>;
    mods = <(MOD_LSFT)>;
)


// Command+Tab swapper, requires PR #1366
ZMK_BEHAVIOR(swapper, tri_state,
    bindings = <&kt LGUI>, <&kp TAB>, <&kt LGUI>;
    ignored-key-positions = <LB2>; // ignored key should be position of SWAP_PREV
)

// tap: comma | shift + tap: semicolon | ctrl + shift + tap: <
ZMK_BEHAVIOR(comma_morph, mod_morph,
    mods = <(MOD_LSFT|MOD_RSFT)>;
    bindings = <&kp COMMA>, <&comma_inner_morph>;
)
ZMK_BEHAVIOR(comma_inner_morph, mod_morph,
    bindings = <&kp SEMICOLON>, <&kp LESS_THAN>;
    mods = <(MOD_LCTL|MOD_RCTL)>;
)

// tap: dot | shift + tap: colon | ctrl + shift + tap: >
ZMK_BEHAVIOR(dot_morph, mod_morph,
    bindings = <&kp DOT>, <&dot_inner_morph>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)
ZMK_BEHAVIOR(dot_inner_morph, mod_morph,
    bindings = <&kp COLON>, <&kp GREATER_THAN>;
    mods = <(MOD_LCTL|MOD_RCTL)>;
)

// tap: qmark | shift + tap: excl
ZMK_BEHAVIOR(qexcl, mod_morph,
    bindings = <&kp QMARK>, <&kp EXCL>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
)


// tap: space | shift + tap: underscore | hold: activate layer
ZMK_BEHAVIOR(lt_spc, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&spund>;
)
ZMK_BEHAVIOR(spund, mod_morph,
  bindings = <&kp SPACE>, <&kp UNDERSCORE>;
  mods = <(MOD_LSFT|MOD_RSFT)>;
)

// tap: backspace | lshft + tap: delete | rshft + tap: shift-delete | hold: activate layer
ZMK_BEHAVIOR(lt_del, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&bs_del>;

)
ZMK_BEHAVIOR(bs_del, mod_morph,
    bindings = <&kp BSPC>, <&kp DEL>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
    keep-mods = <MOD_RSFT>;
)

// tap: sticky shift | double-tap: sticky num-layer | hold: num-layer
#define SHFT_NUM &shift_num NUM 0
ZMK_BEHAVIOR(shift_num, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&sticky_num_dance>;
)
ZMK_BEHAVIOR(sticky_num_dance, tap_dance,
    tapping-term-ms = <300>;
    bindings = <&sk LSHFT>, <&sl NUM>;  // reverse this for sticky-num on single tap
)
&num_word {  // num-word, requires PR #1441
    layers = <NUM>;
};


// tap: caps word | double-tap: caps lock
ZMK_BEHAVIOR(caps_dance, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&caps_word>, <&kp CAPS>;
)

