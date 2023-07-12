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
#define SPC_UNDO  &kp LC(LA(LG(Z)))


// NUM Layer Home row mods
#define NUM_N0     &hml LCTRL N0
#define NUM_N4     &hml LALT N4
#define NUM_N5     &hml LGUI N5
#define NUM_N6     &hml LSHFT N6

#define NUM_LBKT   &hmr RSHFT LBKT
#define NUM_RBKT   &hmr RGUI RBKT
#define NUM_EQUAL  &hmr RALT EQUAL
#define NUM_PRCNT  &hmr LCTRL PRCNT

// NAV Layer Home row mods
#define DSK_PREV    &hml LCTRL LC(LEFT)      // previous desktop
#define DSK_NEXT    &hml LALT LC(RIGHT)      // next     desktop
#define PREV_WINDOW &hml LGUI LS(LG(GRAVE))
#define NEXT_WINDOW &hml LSHFT LG(GRAVE)

// TODO - figure out way to get swapper on index + middle finger with home row mods
#define SWAP_PREV   &kp LS(TAB) // I'd like this to still work as a home row mod, but doesn't work with tri-state swapper
// #define SWAPPER     &hml LSHFT &swapper // This doesn't work TODO - figure out how to bind swapper into a hold-tap

// Left Hand Hyper Layer
// Might be a little excessive to do this just to get the fancy copy/paste thumb keys
#define HYP_N1 &kp LS(LG(LA(LC(N1))))
#define HYP_N2 &kp LS(LG(LA(LC(N2))))
#define HYP_N3 &kp LS(LG(LA(LC(N3))))
#define HYP_N4 &kp LS(LG(LA(LC(N4))))
#define HYP_N5 &kp LS(LG(LA(LC(N5))))
#define HYP_Q &kp LS(LG(LA(LC(Q))))
#define HYP_W &kp LS(LG(LA(LC(W))))
#define HYP_F &kp LS(LG(LA(LC(F))))
#define HYP_P &kp LS(LG(LA(LC(P))))
#define HYP_B &kp LS(LG(LA(LC(B))))
#define HYP_A &kp LS(LG(LA(LC(A))))
#define HYP_R &kp LS(LG(LA(LC(R))))
#define HYP_S &kp LS(LG(LA(LC(S))))
#define HYP_T &kp LS(LG(LA(LC(T))))
#define HYP_G &kp LS(LG(LA(LC(G))))
// Only Z doesn't have a hyper shortcut, instead it has a shortcut to command+z for undo
#define HYP_X &kp LS(LG(LA(LC(X))))
#define HYP_C &kp LS(LG(LA(LC(C))))
#define HYP_D &kp LS(LG(LA(LC(D))))
#define HYP_V &kp LS(LG(LA(LC(V))))
#define HYP_MINUS &kp LS(LG(LA(LC(MINUS))))
#define HYP_EQUAL &kp LS(LG(LA(LC(EQUAL))))
#define HYP_LEFT &kp LS(LG(LA(LC(LEFT))))
#define HYP_RIGHT &kp LS(LG(LA(LC(RIGHT))))

// Right hand hyper keys
// need this to be able to preserve plain hyper modifier behavior on right hand while using left hyper key
#define HYP_N6 &kp LS(LG(LA(LC(N6))))
#define HYP_N7 &kp LS(LG(LA(LC(N7))))
#define HYP_N8 &kp LS(LG(LA(LC(N8))))
#define HYP_N9 &kp LS(LG(LA(LC(N9))))
#define HYP_N0 &kp LS(LG(LA(LC(N0))))
#define HYP_J &kp LS(LG(LA(LC(J))))
#define HYP_L &kp LS(LG(LA(LC(L))))
#define HYP_U &kp LS(LG(LA(LC(U))))
#define HYP_Y &kp LS(LG(LA(LC(Y))))
#define HYP_SQT &kp LS(LG(LA(LC(SQT))))
#define HYP_M &kp LS(LG(LA(LC(M))))
#define HYP_N &kp LS(LG(LA(LC(N))))
#define HYP_E &kp LS(LG(LA(LC(E))))
#define HYP_I &kp LS(LG(LA(LC(I))))
#define HYP_O &kp LS(LG(LA(LC(O))))
#define HYP_K &kp LS(LG(LA(LC(K))))
#define HYP_H &kp LS(LG(LA(LC(H))))
#define HYP_COMMA &kp LS(LG(LA(LC(COMMA))))
#define HYP_DOT &kp LS(LG(LA(LC(DOT))))
#define HYP_QMARK &kp LS(LG(LA(LC(QMARK))))
#define HYP_UP &kp LS(LG(LA(LC(UP))))
#define HYP_DOWN &kp LS(LG(LA(LC(DOWN))))
#define HYP_LBKT &kp LS(LG(LA(LC(LBKT))))
#define HYP_RBKT &kp LS(LG(LA(LC(RBKT))))
// hyper + nav specific
#define HYP_RET &kp LS(LG(LA(LC(RET))))
#define HYP_TAB &kp LS(LG(LA(LC(TAB))))
#define HYP_ESC &kp LS(LG(LA(LC(ESC))))

// misc aliases
#define LOCK_SCRN   &kp LC(LG(Q))
#define NUM_MULTI   &kp KP_MULTIPLY
#define CANCEL      &kp K_CANCEL             // cancel caps-word, num-word and smart-mouse
// #define LHYP      LS(LC(LA(LGUI)))
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

