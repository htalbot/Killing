
#pragma once

#define KILLING_MAJOR 1
#define KILLING_MINOR 0
#define KILLING_PATCH 2


#if defined _MSC_VER
#   ifdef _DEBUG
        const char KILLING_DebugFlag[] = "DEBUG";
#   else
        const char KILLING_DebugFlag[] = "RELEASE";
#   endif
#else
#   ifdef DEBUG
        const char KILLING_DebugFlag[] = "DEBUG";
#   else
        const char KILLING_DebugFlag[] = "RELEASE";
#   endif
#endif


