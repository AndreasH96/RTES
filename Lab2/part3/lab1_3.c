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
void lcd_Execution();
unsigned long  getTimerValue();
/*--------------------------------*/

volatile uint8_t taylorInput = 1;

void lcd_Execution()
{
    piface_clear();                             // Clear the display from old characters
    ExpStruct *result = iexp(taylorInput);      // Calc the really bad approx of e^n
    char printStringLCD[16];
    sprintf(printStringLCD, "%d:%d.%d\n", taylorInput, result->expInt, result->expFraction);   // Format the values to string
    piface_puts(printStringLCD);                // Print the string to the LCD

    free(result);                               // Free the allocated memory
    taylorInput += 1;                           // Increase the input 'till next time we call the function
}

// Function to reade the System Timer registers and make the two int's to a long
unsigned long getTimerValue(){
    unsigned int lower32 = *SYSTEMTIMER_LOWER32;
    unsigned int higher32 = *SYSTEMTIMER_HIGHER32;
    unsigned long timerValue = (higher32 << 32) | lower32;
    return timerValue;
}
int main()
{   
    // Init the LED
    led_init();

    // We calculate how long in clockcycles the lcd_Execution() function takes to execute, 
    // in order to have an dynamic delay in order to make the LED blink with constant interval
    for (int i = 0; i < 100; i++)
    {   
        char printString[16];
        unsigned long startTimeLCD = getTimerValue();
        lcd_Execution();
        unsigned long deltaTimeLCD = getTimerValue() - startTimeLCD ;
        sprintf(printString, "ClkC:%ld\n", deltaTimeLCD);

        piface_puts(printString);
        delay(DELAYTIME - deltaTimeLCD);

        led_blink(deltaTimeLCD);
        
    }
    return 0;
}

