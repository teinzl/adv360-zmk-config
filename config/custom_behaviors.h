#include "./adv360pro_keypos.h"
#include "./zmk_helper.h"

/* Global settings */

#define QUICK_TAP_MS 175

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
MAKE_HRM(hml, &kp, &kp, KEYS_R THUMBS)  // left-hand HRMs
MAKE_HRM(hmr, &kp, &kp, KEYS_L THUMBS)  // right-hand HRMs
MAKE_HRM(hml_repeat, &kp, &key_repeat, KEYS_R THUMBS)  // left-hand HRM for repeat combo

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
#define NAV_UP    &mt LC(HOME) UP      // tap: up    | long-tap: beginning of document
#define NAV_DOWN  &mt LC(END)  DOWN    // tap: down  | long-tap: end       of document
#define NAV_BSPC  &mt LC(BSPC) BSPC    // tap: bspc  | long-tap: delete word backward
#define NAV_DEL   &mt LC(DEL)  DEL     // tap: del   | long-tap: delete word forward

#define SPC_UP    &kp LC(LG(UP))
#define SPC_DOWN  &kp LC(LG(DOWN))
#define SPC_LEFT  &kp LA(LG(LEFT))
#define SPC_RIGHT &kp LA(LG(RIGHT))
#define SPC_FULL  &kp LA(LG(F))
#define SPC_MVR   &kp LC(LA(LG(RIGHT)))
#define SPC_MVL   &kp LC(LA(LG(LEFT)))

// NUM Layer Home row mods
#define NUM_MULTI  &kp KP_MULTIPLY
#define NUM_DIVIDE &hml LCTRL KP_DIVIDE
#define NUM_N4     &hml LALT N4
#define NUM_N5     &hml LGUI N5
#define NUM_N6     &hml LSHFT N6

#define NUM_LBRC   &hmr RSHFT LBRC
#define NUM_EQUAL  &hmr RGUI EQUAL
#define NUM_RBRC   &hmr RALT RBRC
#define NUM_AT     &hmr LCTRL AT

// misc aliases
#define CANCEL      &kp K_CANCEL             // cancel caps-word, num-word and smart-mouse
#define DSK_PREV    &hmr RSHFT LC(LEFT)      // previous desktop
#define DSK_NEXT    &hmr RALT LC(RIGHT)      // next     desktop
#define VOL_DOWN    &hmr LGUI C_VOL_DN

#define NEXT_WINDOW &kp LG(GRAVE)
#define PREV_WINDOW &kp LS(LG(GRAVE))

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
    ignored-key-positions = <LT2>;
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

// tap: end | hold: command
ZMK_BEHAVIOR(end_cmd, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <200>;
    bindings = <&kp LGUI>, <&kp END>;
)

// tap: page down | hold: command
ZMK_BEHAVIOR(pgdn_cmd, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <200>;
    bindings = <&kp LGUI>, <&kp PG_DN>;
)



// tap: backspace | lshft + tap: delete | rshft + tap: shift-delete
ZMK_BEHAVIOR(bs_del, mod_morph,
    bindings = <&kp BSPC>, <&kp DEL>;
    mods = <(MOD_LSFT|MOD_RSFT)>;
    keep-mods = <MOD_RSFT>;
)




// TODO - I want to put this on a layer so I can hold a thumb key, then either single or double tap c
// tap: copy | double-tap: cut
ZMK_BEHAVIOR(copy_cut, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&kp LG(C)>, <&kp LG(X)>;
)


// tap: num-word | double-tap: sticky num-layer | hold: num-layer
#define SMART_NUM &smart_num NUM 0
ZMK_BEHAVIOR(smart_num, hold_tap,
    flavor = "balanced";
    tapping-term-ms = <200>;
    quick-tap-ms = <QUICK_TAP_MS>;
    bindings = <&mo>, <&num_dance>;
)
ZMK_BEHAVIOR(num_dance, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&num_word>, <&sl NUM>;  // reverse this for sticky-num on single tap
)
&num_word {  // num-word, requires PR #1441
    layers = <NUM>;
};


// tap: caps word | double-tap: caps lock
ZMK_BEHAVIOR(caps_dance, tap_dance,
    tapping-term-ms = <200>;
    bindings = <&caps_word>, <&kp CAPS>;
)

