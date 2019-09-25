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

void led_init();

void led_blink();

#endif