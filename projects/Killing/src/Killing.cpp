
#include "Killing/Killing.h"
#include "Killing/version.h"
#include "ace/Log_Msg.h"

#ifdef ACE_WIN32
#include <tlhelp32.h>
#include <Psapi.h>
#pragma comment ( lib, "psapi.lib" )
#endif


namespace Killing_ns
{
    void killing_get_version(int & major, int & minor, int & patch)
    {
        major = KILLING_MAJOR;
        minor = KILLING_MINOR;
        patch = KILLING_PATCH;
    }

    bool Killing::kill_process_by_name(char * szProcessToKill)
    {
#ifdef ACE_WIN32
        HANDLE hProcessSnap;
        HANDLE hProcess;
        PROCESSENTRY32 pe32;

        hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  // Takes a snapshot of all the processes

        if (hProcessSnap == INVALID_HANDLE_VALUE)
        {
            return false;
        }

        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hProcessSnap, &pe32))
        {
            CloseHandle(hProcessSnap);
            return false;
        }

        do
        {
            //ACE_DEBUG((LM_DEBUG, "proc: %s\n", pe32.szExeFile));
            if(!strcmp(pe32.szExeFile, szProcessToKill))
            {
                //  checks if process at current position has the name of to be killed app
                hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe32.th32ProcessID);  // gets handle to process
                TerminateProcess(hProcess, 0);   // Terminate process by handle
                CloseHandle(hProcess);  // close the handle
            }
        } while (Process32Next(hProcessSnap, &pe32));  // gets next member of snapshot

        CloseHandle(hProcessSnap);  // closes the snapshot handle
#else
    #warning Killing::kill_process_by_name() not implemented in Linux
    ACE_UNUSED_ARG(szProcessToKill);
#endif
        return true;
    }

    void Killing::suicide()
    {
#ifdef ACE_WIN32
        const DWORD size(2048);
        char szModulename[size];
        GetModuleBaseName(GetCurrentProcess(), NULL, szModulename, size);

        ACE_Guard<ACE_Recursive_Thread_Mutex> guard(this->mutex());
        kill_process_by_name(szModulename);
#else
    #warning Killing::suicide() not implemented in Linux
#endif
    }

    ACE_Recursive_Thread_Mutex & Killing::mutex()
    {
        return protect_critical_op_mutex_;
    }

} // Killing_ns namespace
