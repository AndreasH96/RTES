#include "taylorSeries.h"
#include <stdlib.h>
#include <stdio.h>
#include "led.h"


ExpStruct * iexp(unsigned int x,int *counter){
    ExpStruct* eAprox = malloc(sizeof(ExpStruct));
    if(eAprox == NULL){
        return NULL;
    }
    
    long double calcVal = 1.0;
    unsigned int n = abs(x) + 1;
    double fact = 1.0;
    unsigned int xOld = x;
    for(int i = 1; i < n; i++){
        fact = fact * i;
        //calcVal = calcVal + ((long double)powerOf(x, i, counter)/fact);
        xOld = xOld*x;
        calcVal = calcVal + xOld/fact;
        *counter++;
        if(*counter % 10 == 0){
            led_blink();
        }
    }
    
    eAprox->expInt = (unsigned long) calcVal;
    eAprox->expFraction = (unsigned long) ((calcVal - (long double)eAprox->expInt)*100.0);
    return eAprox;
}
