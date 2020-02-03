/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2016, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

// Assignment made by Karl-Johan Djervbrant and Andreas Häggström

#include <rpi3.h>
#include <stdio.h>
#include "iregister.h"
#include "led.h"

iRegister *GPIO_GPFSEL1, *GPIO_GPSET0, *GPIO_GPCLR0;

volatile uint8_t toggle = 0;

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
}

void led_blink()
{

    setBit(16, GPIO_GPSET0);
    delay(1000);
    setBit(16, GPIO_GPCLR0);
    delay(1000);

}