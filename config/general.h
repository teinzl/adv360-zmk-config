#define QUICK_TAP_MS 175


// long-tap action on hold, short-tap action on all interrupts
#define MT_CORE \
    flavor = "tap-preferred"; \
    tapping-term-ms = <220>; \
    quick-tap-ms = <220>; \
    hold-trigger-key-positions = <0>;

&mt { MT_CORE };
