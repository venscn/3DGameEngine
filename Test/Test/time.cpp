//
//  time.cpp
//  OpenGLGameEngine
//
//  Created by Mark Diedercks on 31/03/2014.
//  Copyright (c) 2014 bennybox & marko5049. All rights reserved.
//

#include "sys/time.h"
#include "time.h"

double Time::getTime() {
    timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return (currentTime.tv_sec * 1000) + (currentTime.tv_usec / 1000);
}