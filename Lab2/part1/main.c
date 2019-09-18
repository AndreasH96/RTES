#include <stdio.h>
#include "taylorSeries.h"
#include <CUnit/CUnit.h>

// struct assembledValue{
//     double value;
// }
// assembledValue assembleExpStruct(int intValue, int fractValue){
//     double fract = fractValue/100;
    
// }
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
    
}