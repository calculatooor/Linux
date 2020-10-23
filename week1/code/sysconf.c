#include "ch01.h"

int have_job_control(void)
{
    #ifdef _POSIX_JOB_CONTROL
        return 1;
    #else
        int value;
        errno=0;
        value=sysconf(_SC_JOB_SCOTROL);
        if(value<0)
            if(errno==0)
                value=0;
            else
                fatal(strerror(errno));
        return value;
        
        
    #endif
}

int main()
{
    int i=have_job_control();
    printf("operating system support JOB_SCOTROL:%d\n",i);
}