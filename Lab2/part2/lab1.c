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
    volatile uint8_t taylorInput = 1;
    
    while (1)
    {
        piface_clear();
        ExpStruct *result = iexp(taylorInput);      // Calc the really bad approx of e^n 
        char printStringLCD[16]  ;
        sprintf(printStringLCD, "%d:%d.%d", taylorInput, result->expInt, result->expFraction);
        piface_puts(printStringLCD);
        taylorInput +=1;
        piface_delay(10000000);

        free(result);
        
    }

	return 0;
}