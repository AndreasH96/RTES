#include <stdio.h>

typedef struct  {
int expInt;
int expFraction;
}ExpStruct;



/* 
@description Rougly estimates the value of e^n where n is the input value with two degrees of precision. Returns in a struct 
with its integer part and its fractional part.

@pre-condition  n != NULL

@post-condition a struct of type ExpStruct is returned, containing two values, expInt which will be the integer value of the result and 
expFraction will be the two first decimal values of the result.

@test-cases 
1. Call the function, check for correct value

*/
ExpStruct * iexp ( int );

/* int powerOf(int base, int exp)
@description Calculates the value of base^exp and returns it as an int.

@pre-condition  base && exp != NULL

@post-condition an integer is returned, containg the resulting value of the calculation base^exp

@test-cases 
1. Call the function, check for correct value

*/

int powerOf(int, int);