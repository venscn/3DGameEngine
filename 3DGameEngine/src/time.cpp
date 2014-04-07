#include "time.h"
#include <time.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WIN64)
	#define OS_WINDOWS
#elif defined(__linux__)
	#define OS_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
    #define OS_MACOSX
#elif __cplusplus >= 201103L
	#define OS_OTHER_CPP11
#else
	#define OS_OTHER
#endif

#ifdef OS_WINDOWS
	#include <Windows.h>
	#include <iostream>
	static double g_freq;
	static bool g_timerInitialized = false;
#endif

#ifdef OS_LINUX
	#include <sys/time.h>
    static const long NANOSECONDS_PER_SECOND = 1000000000L;
#endif

#ifdef OS_MACOSX
    #include <mach/mach.h>
    #include <mach/mach_time.h>
#endif

#ifdef OS_OTHER
	#include <SDL2/SDL.h>
#endif

#ifdef OS_OTHER_CPP11
	#include <chrono>
	static std::chrono::steady_clock::time_point m_epoch = std::chrono::high_resolution_clock::now();
#endif

double Time::GetTime()
{
	#ifdef OS_WINDOWS
		if(!g_timerInitialized)
		{
			LARGE_INTEGER li;
			if(!QueryPerformanceFrequency(&li))
				std::cerr << "QueryPerformanceFrequency failed in timer initialization"  << std::endl;
			
			g_freq = double(li.QuadPart);
			g_timerInitialized = true;
		}
	
		LARGE_INTEGER li;
		if(!QueryPerformanceCounter(&li))
			std::cerr << "QueryPerformanceCounter failed in get time!" << std::endl;
		
		return double(li.QuadPart)/g_freq;
	#endif
    
    #ifdef OS_MACOSX
        static mach_timebase_info_data_t timeBase;
        uint64_t time = mach_absolute_time();
        (void) mach_timebase_info(&timeBase);
        return ((double)((time * timeBase.numer) / timeBase.denom))/1000000000.0;
    #endif

	#ifdef OS_LINUX
		timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		return (double)(((long) ts.tv_sec * NANOSECONDS_PER_SECOND) + ts.tv_nsec)/((double)(NANOSECONDS_PER_SECOND));
	#endif

	#ifdef OS_OTHER_CPP11
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_epoch).count() / 1000000000.0;
	#endif

	#ifdef OS_OTHER
		return (double)SDL_GetTicks()/1000.0;
	#endif
}
