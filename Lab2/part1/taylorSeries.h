#include <stdio.h>

struct expStruct {
int expInt;
int expFraction;
};

typedef struct expStruct ExpStruct;

/* 
@description Calculates the value of e^n where n is the input value with two degrees of precision. Returns in a struct 
with its integer part and its fractional part.

@pre-condition  n != NULL

@post-condition a struct of type ExpStruct is returned, containing two values, expInt which will be the integer value of the result and 
expFraction will be the two first decimal values of the result.

@test-cases 
1. Call the function

*/
ExpStruct * iexp ( int );