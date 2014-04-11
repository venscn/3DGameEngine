#include "time.h"
#include <time.h>
#include <mach/mach.h>
#include <mach/mach_time.h>

double Time::GetTime()
{
    static mach_timebase_info_data_t timeBase;
    uint64_t time = mach_absolute_time();
    (void) mach_timebase_info(&timeBase);
    return ((double)((time * timeBase.numer) / timeBase.denom))/1000000000.0;
}
