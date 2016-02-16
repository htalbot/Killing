
#ifndef __TEST_KILLING_VERSION_H__
#define __TEST_KILLING_VERSION_H__

#define TEST_KILLING_MAJOR 1
#define TEST_KILLING_MINOR 0
#define TEST_KILLING_PATCH 2


#if defined _MSC_VER
#   ifdef _DEBUG
        const char TEST_KILLING_DebugFlag[] = "DEBUG";
#   else
        const char TEST_KILLING_DebugFlag[] = "RELEASE";
#   endif
#else
#   ifdef DEBUG
        const char TEST_KILLING_DebugFlag[] = "DEBUG";
#   else
        const char TEST_KILLING_DebugFlag[] = "RELEASE";
#   endif
#endif


#endif // __TEST_KILLING_VERSION_H__
