// #include "taylorSeries.h"
// #include <stdlib.h>
// #include <stdio.h>

// ExpStruct * iexp(int x){
//     ExpStruct* eAprox = calloc(1, sizeof(ExpStruct));
//     double calcVal = 1.0;
//     int n = abs(x) + 1;
//     double fact = 1.0;

//     for(int i = 1; i < n; i++){
//         fact = fact * i;
//         calcVal = calcVal + ((double)powerOf(x, i)/fact);
//     }
    
//     eAprox->expInt = (int) calcVal;
//     eAprox->expFraction = (int) ((calcVal - (double)eAprox->expInt)*100.0);
//     return eAprox;
// }

// int powerOf(int base, int exp){
//     int retVal = 1;
//     for(int i = 0; i<exp; i++){
//         retVal *= base; 
//     }
//     return retVal;
// }

#include "taylorSeries.h"
#include <stdlib.h>
#include <stdio.h>

ExpStruct * iexp(unsigned int x){
    ExpStruct* eAprox = malloc(sizeof(ExpStruct));
    if(eAprox == NULL){
        return NULL;
    }
    
    long double calcVal = 1.0;
    unsigned int n = abs(x) + 1;
    double fact = 1.0;

    for(int i = 1; i < n; i++){
        fact = fact * i;
        calcVal = calcVal + ((long double)powerOf(x, i)/fact);
    }
    
    eAprox->expInt = (unsigned long) calcVal;
    eAprox->expFraction = (unsigned long) ((calcVal - (long double)eAprox->expInt)*100.0);
    return eAprox;
}

unsigned int powerOf(unsigned int base,unsigned int exp){
    unsigned long retVal = 1;
    for(int i = 0; i<exp; i++){
        retVal *= base; 
    }
    return retVal;
}