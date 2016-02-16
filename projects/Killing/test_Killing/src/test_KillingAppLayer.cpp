
#include "test_killingAppLayer.h"
#include "Killing/Killing.h"
#include "ace/Task.h"

using namespace Killing_ns;

#include <stdio.h>

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

class T: public ACE_Task_Base
{
public:
    int svc()
    {
        ACE_DEBUG((LM_DEBUG, "T:svc...\n"));
        {
            ACE_Guard<ACE_Recursive_Thread_Mutex> guard(KILLING->mutex());
            ACE_DEBUG((LM_DEBUG, "T:svc protected against killing until the end of this block.\n"));
            ACE_DEBUG((LM_DEBUG, "Should not see the message: \"See that??? Not supposed.\".\n"));
            ACE_OS::sleep(5);
        }
        
        ACE_DEBUG((LM_DEBUG, "T:svc block ended.\n"));
        ACE_OS::sleep(3);
        ACE_DEBUG((LM_DEBUG, "See that??? Not supposed.\n"));
        
        return 0;
    }
};


Test_killingAppLayer::Test_killingAppLayer()
{
}


bool Test_killingAppLayer::run()
{
    printf("***** Test_killingAppLayer (%s) *****\n\n", TEST_KILLING_DebugFlag);

    int major, minor, patch;
    killing_get_version(major, minor, patch);
    printf("killing version: %d.%d.%d\n", major, minor, patch);

    T t;
    t.activate();

    ACE_OS::sleep(1);

    ACE_DEBUG((LM_DEBUG, "Suicide...\n"));
    KILLING->suicide();

    printf("Killed => not reached.\n");

    return true;
}

