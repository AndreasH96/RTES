#ifndef lab1_3_led_h
#define lab1_3_led_h
#define DELAYTIME 500000


/* void delay(int cycles)
@description Performs a no-operation for int cycles

@pre-condition cycles != null && cycles > 0

@post-condition the running thread is paused for the given amount of cycles. No register values
are affected. 

*/
void delay(int);

/* void led_init()
@description init the LED with GPIO16
*/
void led_init();

/* void led_blink(unsigned int deltaTime)
@description Blink the LED, deltaTime is subtracted from the delay to make it dynamic

@pre-condition deltaTime > 0 && deltaTime != NULL

@post-condition The LED blinks one time

*/
void led_blink();

#endif