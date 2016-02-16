
#ifndef __KILLING_H__
#define __KILLING_H__

#include "Killing/KILLING_Export.h"
#include "Killing/version.h"
#include "ACEWin64Warnings/BeginSuppressWarnings.h"
#include "ace/Singleton.h"
#include "ace/Synch.h"
#include "ACEWin64Warnings/EndSuppressWarnings.h"

namespace Killing_ns
{
    extern "C" KILLING_Export void killing_get_version(int & major, int & minor, int & patch);

    class KILLING_Export Killing
    {
        friend ACE_Singleton<Killing_ns::Killing, ACE_Recursive_Thread_Mutex>;

    public:
		bool kill_process_by_name(char * szProcessToKill);
		void suicide();
        ACE_Recursive_Thread_Mutex & mutex();

    protected:
        ACE_Recursive_Thread_Mutex protect_critical_op_mutex_;
	};

} // Killing_ns namespace


typedef ACE_Singleton<Killing_ns::Killing, ACE_Recursive_Thread_Mutex> KillingSingleton;

#ifdef ACE_WIN32
    #pragma warning(push)
    #pragma warning(disable: 4231) // will disapear when VC is conform to C++11
#endif
    KILLING_SINGLETON_DECLARE(ACE_Singleton, Killing_ns::Killing, ACE_Recursive_Thread_Mutex);
#ifdef ACE_WIN32
    #pragma warning(push)
#endif


#define KILLING KillingSingleton::instance()


#endif // __KILLING_H__
