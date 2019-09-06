/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <rpi3.h>
#include <stdio.h>
#include<time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{
    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 16);
    
    /* Turn LED on */
    GPIO->GPSET1 |= (1 << 16);

    int delayTime = 2;

    while(1) 
    {
        /* Iteratively turn on and off the LED */
        //delay(delayTime);
        /* Turn LED off */
        //GPIO->GPSET0 |= ~(1 << 16);
        //delay(200);
        /* Turn LED on */
        //GPIO->GPSET0 |= (1 << 16);

        //delayTime *= 2;
    }

	return 0;
}