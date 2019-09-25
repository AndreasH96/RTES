/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

// Assignment made by Karl-Johan Djervbrant and Andreas Häggström

#include <rpi3.h>
#include <stdio.h>
#include "iregister.h"
iRegister *GPIO_GPFSEL1,*GPIO_GPSET0,* GPIO_GPCLR0;
void delay(int cycles)
{   
    while (cycles-- > 0){
        asm("");
    };
}

int main()
{
    GPIO_GPFSEL1 = &GPIO->GPFSEL1;
    GPIO_GPSET0 = &GPIO->GPSET0;
    GPIO_GPCLR0 = &GPIO->GPCLR0;

    volatile int delayTime = 1000;
    /* Enable GPIO16 as an output */
    setBit(18, GPIO_GPFSEL1);
    //GPIO->GPFSEL1 |= (1 << 18); 
     
    /* Turn LED on */
    setBit(16,GPIO_GPSET0);
    //GPIO->GPSET0 |= (1 << 16);
    
    while(1) 
    {
        /* Iteratively turn on and off the LED */
        delay(1000000);
        /* Turn LED off */
        setBit(16,GPIO_GPCLR0);
        //GPIO->GPCLR0 |= (1 << 16);
        delay(delayTime);
        /* Turn LED on */
        setBit(16,GPIO_GPSET0);
        //GPIO->GPSET0 |= (1 << 16);

        delayTime *= 2;
    }

	return 0;
}