/* Copyright (c) 2005 Russ Cox, MIT; see COPYRIGHT */

#include <stdio.h>
#include <task.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
FILE *primesFile, *workingPrimesFile;
char primesPath[INT8_MAX];
char workingPrimesPath[INT8_MAX];



void testPrimes(){
       
    primesFile = popen("./primes 100","r");
    workingPrimesFile = popen("./working_primes 100","r");
    int i =1;
    CU_ASSERT(1 == 1);
    while (fgets(primesPath,INT8_MAX,primesFile) != NULL){
        fgets(workingPrimesPath,INT8_MAX,workingPrimesFile);
        
        CU_ASSERT(strcmp(primesPath,workingPrimesPath) == 0);
    }
    
}

int main()
{
    CU_initialize_registry();
    CU_pSuite testSuite = CU_add_suite("testPrimes", 0,0);
    CU_add_test(testSuite, "Primes test", testPrimes);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
   return 0; 
}

