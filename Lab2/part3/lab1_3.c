/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

#include <stdio.h>
#include "rpi3.h"
#include "piface.h"
#include "taylorSeries.h"
#include "led.h"
#include <time.h>

/*------Function Declaration------*/
void lcd_Execution();
/*--------------------------------*/

volatile uint8_t taylorInput = 1;

void lcd_Execution()
{
    piface_clear();
    ExpStruct *result = iexp(taylorInput);
    char printString[31];
    sprintf(printString, "%d: %ld.%d", taylorInput, result->expInt, result->expFraction);
    piface_puts(printString);
    taylorInput += 1;
}

int main()
{
    led_init();
    
    for (int i = 0; i < 20; i++)
    {   
        led_blink();
        lcd_Execution();
        delay(DELAYTIME);
    }
    return 0;
}
