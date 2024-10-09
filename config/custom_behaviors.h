ZMK_BEHAVIOR(macro_tt, macro, 
bindings = <&kt LSHFT>, <&kp T>, <&kt LSHFT>;
)
ZMK_BEHAVIOR(macro_rr, macro,
bindings = <&kt LSHFT>, <&kp R>, <&kt LSHFT>;
)
ZMK_BEHAVIOR(macro_ee, macro,
bindings = <&kt LSHFT>, <&kp E>, <&kt LSHFT>;
)
ZMK_BEHAVIOR(macro_ww, macro,
bindings = <&kt LSHFT>, <&kp W>, <&kt LSHFT>;
)
ZMK_BEHAVIOR(macro_qq, macro,
bindings = <&kt LSHFT>, <&kp Q>, <&kt LSHFT>;
)
ZMK_BEHAVIOR(macro_koreancombo_sg, macro,
bindings = <&kp S>, <&kp G>;
)
ZMK_BEHAVIOR(macro_alt_cap, macro,
bindings = <&kt LEFT_ALT>, <&kp CAPS>, <&kt LEFT_ALT>;
)

ZMK_BEHAVIOR(macro_shift_5, macro,
bindings = <&kt RSHFT>, <&kp N5>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_4, macro,
bindings = <&kt RSHFT>, <&kp N4>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_3, macro,
bindings = <&kt RSHFT>, <&kp N3>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_2, macro,
bindings = <&kt RSHFT>, <&kp N2>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_1, macro,
bindings = <&kt RSHFT>, <&kp N1>, <&kt RSHFT>;
)

ZMK_BEHAVIOR(macro_shift_t, macro,
bindings = <&kt RSHFT>, <&kp T>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_r, macro,
bindings = <&kt RSHFT>, <&kp R>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_e, macro,
bindings = <&kt RSHFT>, <&kp E>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_w, macro,
bindings = <&kt RSHFT>, <&kp W>, <&kt RSHFT>;
)
ZMK_BEHAVIOR(macro_shift_q, macro,
bindings = <&kt RSHFT>, <&kp Q>, <&kt RSHFT>;
)

ZMK_BEHAVIOR(macro_ctrl_cap, macro,
bindings = <&kt LCTRL>, <&kp CAPSLOCK>, <&kt LCTRL>;
)
ZMK_BEHAVIOR(macro_lang_change, macro,
bindings = <&kt LALT>, <&kp LEFT_SHIFT>, <&kt LALT>;
)
ZMK_BEHAVIOR(macro_shift_o, macro,
bindings = <&kt LSHFT>, <&kp O>, <&kt LSHFT>;
)
ZMK_BEHAVIOR(macro_shift_p, macro,
bindings = <&kt LCTRL>, <&kp CAPSLOCK>, <&kt LCTRL>;
)
ZMK_BEHAVIOR(macro_alttab_cap, macro,
bindings = <&kt LEFT_ALT>, <&kp TAB>, <&kt LEFT_ALT>;
)

ZMK_BEHAVIOR(macro_ctrls, macro,
bindings = <&kt LCTRL>, <&kp S>, <&kt LCTRL>;
)

ZMK_BEHAVIOR(macro_ctrla, macro,
bindings = <&kt LCTRL>, <&kp A>, <&kt LCTRL>;
)

ZMK_BEHAVIOR(macro_ctrlv, macro,
bindings = <&kt LCTRL>, <&kp V>, <&kt LCTRL>;
)

ZMK_BEHAVIOR(macro_ctrlc, macro,
bindings = <&kt LCTRL>, <&kp C>, <&kt LCTRL>;
)

ZMK_BEHAVIOR(macro_ctrlx, macro,
bindings = <&kt LCTRL>, <&kp X>, <&kt LCTRL>;
)

ZMK_BEHAVIOR(macro_ctrlz, macro,
bindings = <&kt LCTRL>, <&kp Z>, <&kt LCTRL>;
)

ZMK_BEHAVIOR(macro_windows_tab, macro,
bindings = <&kt LEFT_WIN>, <&kp TAB>, <&kt LEFT_WIN>;
)

ZMK_BEHAVIOR(macro_quotes, macro,
bindings = <&kp SQT>, <&kp SQT>, <&kp LEFT>;
)

ZMK_BEHAVIOR(macro_dquotes, macro,
bindings = <&kp DQT>, <&kp DQT>, <&kp LEFT>;
)

ZMK_BEHAVIOR(macro_braces, macro,
bindings = <&kp LBRC>, <&kp RBRC>, <&kp LEFT>;
)

ZMK_BEHAVIOR(macro_parens, macro,
bindings = <&kp LPAR>, <&kp RPAR>, <&kp LEFT>;
)

ZMK_BEHAVIOR(macro_brackets, macro,
bindings = <&kp LBKT>, <&kp RBKT>, <&kp LEFT>;
)

ZMK_BEHAVIOR(macro_kinesis, macro,
bindings = <&kp LS(K)>, <&kp I>, <&kp N>, <&kp E>, <&kp S>, <&kp I>, <&kp S>;
)


// autopair macros
ZMK_BEHAVIOR(mbkt, macro,
    bindings = <&macro_tap &kp LBKT &kp RBKT &kp LEFT>;
)
ZMK_BEHAVIOR(mbrc, macro,
    bindings = <&macro_tap &kp LBRC &kp RBRC &kp LEFT>;
)
ZMK_BEHAVIOR(mpar, macro,
    bindings = <&macro_tap &kp LPAR &kp RPAR &kp LEFT>;
)
ZMK_BEHAVIOR(msqt, macro,
    bindings = <&macro_tap &kp SQT &kp SQT &kp LEFT>;
)
ZMK_BEHAVIOR(mdqt, macro,
    bindings = <&macro_tap &kp DQT &kp DQT &kp LEFT>;
)


// tap: sticky-shift | shift + tap/ double-tap: caps-word | hold: shift
//ZMK_BEHAVIOR(smart_shft, mod_morph,
//    bindings = <&sk LSHFT>, <&caps_word>;
//    mods = <(MOD_LSFT)>;
//)


// Command+Tab swapper, requires PR #1366



// Shortcuts and aliases


/* Apple Globe key */
#define C_KEYBOARD_LAYOUT_SELECT (ZMK_HID_USAGE(HID_USAGE_CONSUMER, 0x029D))
#define GLOBE C_KEYBOARD_LAYOUT_SELECT
// As per PR 1938

// Spectacle controls
#define SPC_UP    &kp LA(LG(UP))         // Cycle through upper positions
#define SPC_DOWN  &kp LA(LG(DOWN))       // Cycle through lower positions
#define SPC_LEFT  &kp LA(LG(LEFT))       // Cycle through left positions
#define SPC_RIGHT &kp LA(LG(RIGHT))      // Cycle through right positions
#define SPC_FULL  &kp LA(LG(F))          // Fullscreen
#define SPC_MVR   &kp LC(LA(LG(RIGHT)))  // Move right one screen
#define SPC_MVL   &kp LC(LA(LG(LEFT)))   // Move left one screen
#define SPC_UNDO  &kp LC(LA(LG(Z)))      // Undo last spectacle action

// Mouse Layer command shortcuts
// All keys become tap: command + (key) and long tap: shift + command + (key)
#define Q_F &mt LS(LG(F)) LG(F)
#define Q_P &mt LS(LG(P)) LG(P)
#define Q_B &mt LS(LG(B)) LG(B)
#define Q_G &mt LS(LG(G)) LG(G)
#define Q_Z &mt LS(LG(Z)) LG(Z)
#define Q_X &mt LS(LG(X)) LG(X)
#define Q_C &mt LS(LG(C)) LG(C)
#define Q_D &mt LS(LG(D)) LG(D)
#define Q_V &mt LS(LG(V)) LG(V)

#define LOCK_SCRN   &kp LC(LG(Q))
#define CANCEL      &kp K_CANCEL        // cancel caps-word, num-word and smart-mouse
#define LHYP        LS(LC(LA(LGUI)))
#define RHYP        RS(RC(RA(RGUI)))
#define COPY_CUT    &mt LG(X) LG(C)
#define CMD_PASTE   &kp LG(V)
#define CMD_UNDO    &kp LG(Z)
#define CMD_REDO    &kp LS(LG(Z))
#define PREV_WINDOW &kp LS(LG(GRAVE))
#define NEXT_WINDOW &kp LG(GRAVE)
#define NEXT_TAB    &mtabnext          // next tab in vim or browser(with vimium)
#define PREV_TAB    &mtabprev          // previous tab in vim or browser(with vimium)
#define DSK_PREV    &kp LC(LEFT)       // previous desktop
#define DSK_NEXT    &kp LC(RIGHT)      // next     desktop
#define SWAPPER     &swapper
#define SWAP_PREV   &kp LS(TAB)

// Thumb keys
#define SPC_NAV     &lt_spc NAV 0      // tap: space | shift + tap: underscore | hold: NAV layer
#define RET_HYP     &mt RHYP ENTER     // tap: enter | hold: HYPER key
#define BSPC_SYM    &lt_del SYM 0      // tap: backspace | lshft + tap: delete | rshft + tap: shift-delete | hold: SYM layer
#define SHFT_NUM    &shift_num NUM 0   // tap: sticky shift | double-tap: sticky num layer | hold: NUM layer

/* #define MAKE_LONG_HOLD(NAME, HOLD) \ */
/*     ZMK_BEHAVIOR(NAME, hold_tap, \ */
/*         flavor = "tap-preferred"; \ */
/*         tapping-term-ms = <300>; \ */
/*         quick-tap-ms = <QUICK_TAP_MS>; \ */
/*         bindings = <HOLD, &none>; \ */
/*     ) */
/* MAKE_LONG_HOLD(hbt, &bt) */
// TODO: figure out how to get these things wrapped in a hold tap so that accidental taps don't change the bluetooth profile
#define BT_0 &bt BT_SEL 0
#define BT_1 &bt BT_SEL 1
#define BT_2 &bt BT_SEL 2
#define BT_3 &bt BT_SEL 3
#define BT_4 &bt BT_SEL 4
