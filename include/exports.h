#ifdef UCONFIG_EXPORTS
    #define UCONFIG_API __declspec(dllexport)
#else
    #define UCONFIG_API
#endif