#include <stdio.h>
#include "taylorSeries.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


void testIEXP(){
    
    ExpStruct* returnedValue = iexp(0);
    CU_ASSERT(1 == iexp(0)->expInt);
    CU_ASSERT(0 == iexp(0) ->expFraction);
    CU_ASSERT(1 == returnedValue->expInt && 0 == returnedValue ->expFraction);

    returnedValue = iexp(1);
    CU_ASSERT(2 == returnedValue->expInt);
    CU_ASSERT(0 == returnedValue->expFraction);
    CU_ASSERT(2 == returnedValue->expInt && 0 == returnedValue ->expFraction);

    returnedValue = iexp(2);
    CU_ASSERT(5 == returnedValue->expInt);
    CU_ASSERT(0 == returnedValue->expFraction);
    CU_ASSERT(5 == returnedValue->expInt && 0 == returnedValue ->expFraction);

    returnedValue = iexp(3);
    CU_ASSERT(13 == returnedValue->expInt);
    CU_ASSERT(0 == returnedValue->expFraction);
    CU_ASSERT(13 == returnedValue->expInt && 0 == returnedValue ->expFraction);

    returnedValue = iexp(4);
    CU_ASSERT(34 == returnedValue->expInt);
    CU_ASSERT(33 == returnedValue->expFraction);
    CU_ASSERT(34 == returnedValue->expInt && 33 == returnedValue ->expFraction);

    returnedValue = iexp(-4);
    CU_ASSERT(5 == returnedValue->expInt);
    CU_ASSERT(0 == returnedValue->expFraction);
    CU_ASSERT(5 == returnedValue->expInt && 0 == returnedValue ->expFraction);
    
}


int main(){

    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("testIEXP", 0, 0);

    CU_add_test(suite, "testExponential", testIEXP);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}