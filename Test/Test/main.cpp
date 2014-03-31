//
//  main.cpp
//  OpenGLGameEngine
//
//  Created by Mark on 31/03/2014.
//  Copyright (c) 2014 bennybox&marko5049. All rights reserved.
//

#include "stdio.h"
#include "time.h"

int main() {
    while(true) {
        printf("%d\n", Time::getTime()); //Time is transfered from the time class as a double and in milliseconds!!!
    }
    return 0;
}
