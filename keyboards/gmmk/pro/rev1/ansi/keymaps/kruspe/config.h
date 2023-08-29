#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_TIMEOUT 90000
#endif

// this is for macOS so keyboard can work after sleep
#define NO_USB_STARTUP_CHECK