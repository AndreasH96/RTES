//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>

int main ()
{
  iRegister r;
  char out[33];
  int testResults[10][4]; 

  /* Put all your test cases for the implemented functions here */
  /* Test1: *reg2str(iRegister)
   */
    r.content = 12839238;
    printf("\nTest1: *reg2str(iRegister)\n");
    printf("The value in register r is: %i \n", r.content);
    char* reg2strReturn = reg2str(r);
    char expected [] = "00000000000000000000000000000101";
    printf("The excpected output of *reg2st(iRegister) is: %s\n", expected);
    printf("Output from *reg2str(iRegister) is: %s\n", reg2strReturn);
    if(strcmp(expected, reg2strReturn)== 0){
      printf("Test1, case 1 succeded\n");
      testResults[0][0] = 1;  
    }
    
    
    
  /* Test2: resetAll(iRegister)

   */
    printf("\nTest2: resetAll(iRegister *)\n");
    
    
  return 0;
}
