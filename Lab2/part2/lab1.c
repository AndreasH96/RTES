/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <stdio.h>
#include <rpi3.h>
#include <string.h>
#include "piface.h"
#include <taylorSeries.h>

int main()
{
    /* Write to PiFace's LCD screen */    
    piface_puts("Hello World!\n");

    volatile uint8_t taylorInput = 1;
    
    while (1)
    {
        piface_clear();
        ExpStruct* result = iexp(taylorInput);
        char printString [16];
        sprintf(printString, "%d: %d.%d", taylorInput, result->expInt, result->expFraction);
        piface_puts(printString);
        taylorInput +=1;
        piface_delay(10000000);
        
    }

	return 0;
}