#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
#endif
