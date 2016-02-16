
#include "test_killingAppLayer.h"
#include "ace/Init_ACE.h"
#include <stdio.h>

int main(int, char *[])
{
    ACE::init();

    Test_killingAppLayer app;

    int rc = app.run();

    ACE::fini();

    if (!rc)
    {
        printf("run() failed.\n");
        return -1;
    }

    printf("run() ok.\n");

    return 0;
}
