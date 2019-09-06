/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <rpi3.h>
#include <stdio.h>
#include <time.h>
void delay(int cycles)
{   
    while (cycles-- > 0){
        asm("");
    };
}

int main()
{
    volatile int delayTime = 1000;
    /* Enable GPIO16 as an output */
    GPIO->GPFSEL1 |= (1 << 18);
     
    /* Turn LED on */
    GPIO->GPSET0 |= (1 << 16);
    
    while(1) 
    {
        /* Iteratively turn on and off the LED */
        delay(1000000);
        /* Turn LED off */
        GPIO->GPCLR0 |= (1 << 16);
        delay(delayTime);
        /* Turn LED on */
        GPIO->GPSET0 |= (1 << 16);

        delayTime *= 2;
    }

	return 0;
}