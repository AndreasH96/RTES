/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

// Assignment made by Karl-Johan Djervbrant and Andreas Häggström

#include <rpi3.h>
#include <stdio.h>
#include "iregister.h"
#define DELAYTIME 500000

iRegister *GPIO_GPFSEL1, *GPIO_GPSET0, *GPIO_GPCLR0;

void delay(int cycles)
{
    while (cycles-- > 0)
    {
        asm("");
    };
}
void led_init()
{
    GPIO_GPFSEL1 = &GPIO->GPFSEL1;
    GPIO_GPSET0 = &GPIO->GPSET0;
    GPIO_GPCLR0 = &GPIO->GPCLR0;
    /* Enable GPIO16 as an output */
    setBit(18, GPIO_GPFSEL1);

    /* Turn LED on */
    setBit(16, GPIO_GPSET0);

}

void led_blink()
{

    /* Iteratively turn on and off the LED */
    delay(DELAYTIME);
    /* Turn LED off */
    setBit(16, GPIO_GPCLR0);

    delay(DELAYTIME);
    /* Turn LED on */
    setBit(16, GPIO_GPSET0);
}