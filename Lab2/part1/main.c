#include <stdio.h>
#include "taylorSeries.h"
//#include <CUnit/CUnit.h>

// struct assembledValue{
//     double value;
// }
// assembledValue assembleExpStruct(int intValue, int fractValue){
//     double fract = fractValue/100;
    
// }

/*
void testIEXP(){

    ExpStruct* returnedValue = iexp(0);
    CU_ASSERT(1 == iexp(0)->expInt);
    CU_ASSERT(0 == iexp(0) ->expFraction);
    CU_ASSERT(1 == returnedValue->expInt && 0 == returnedValue ->expFraction);

    returnedValue = iexp(4);
    CU_ASSERT(34 == iexp(0)->expInt);
    CU_ASSERT(34 == iexp(0) ->expFraction);
    CU_ASSERT(34 == returnedValue->expInt && 34 == returnedValue ->expFraction);

    returnedValue == iexp(-4);
    CU_ASSERT(5 == returnedValue->expInt);
    CU_ASSERT(0 == returnedValue->expFraction);
    
}
*/
int main(){

    ExpStruct* e1 = iexp(1);
    ExpStruct* e2 = iexp(2);
    ExpStruct* e3 = iexp(3);
    ExpStruct* e4 = iexp(4);
    
    printf("e^1 = %i.%i\n",e1->expInt, e1->expFraction);
    printf("e^2 = %i.%i\n",e2->expInt, e2->expFraction);
    printf("e^3 = %i.%i\n",e3->expInt, e3->expFraction);
    printf("e^4 = %i.%i\n",e4->expInt, e4->expFraction);
    
    return 0;
}