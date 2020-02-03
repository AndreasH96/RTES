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
// Defining the register addresses to the System Timer
#define SYSTEMTIMER_LOWER32 ((volatile int*) 0x3F003004)
#define SYSTEMTIMER_HIGHER32 ((volatile int*) 0x3F003008)

/*------Function Declaration------*/
void lcd_Execution(int *);
//unsigned long  getTimerValue();
/*--------------------------------*/

volatile uint8_t taylorInput = 1;

void lcd_Execution(int *theCounter)
{
    piface_clear();                             // Clear the display from old characters
    ExpStruct *result = iexp(taylorInput, theCounter);      // Calc the really bad approx of e^n
    char printStringLCD[16];
    sprintf(printStringLCD, "%d:%d.%d\n", taylorInput, result->expInt, result->expFraction);   // Format the values to string
    piface_puts(printStringLCD);                // Print the string to the LCD
    free(result);                               // Free the allocated memory
    taylorInput += 1;                           // Increase the input 'till next time we call the function
}


int main()
{   
    // Init the LED
    led_init();
    int theCounter = 0;

    for (int i = 0; i < 100; i++)
    {   
        lcd_Execution(&theCounter);
    }
    return 0;
}

