//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"

int main ()
{
  iRegister r;
  char out[33];

  /* Put all your test cases for the implemented functions here */
  /* Test1: *reg2str(iRegister)
   */
    r.content = 5;
    printf("\nTest1: *reg2str(iRegister)\n");
    printf("The value in register r is: %i \n", r.content);
    char* reg2strReturn = reg2str(r);
    printf("This in binary using *reg2str(iRegister) is: %s\n", reg2strReturn);
    printf("Testing if the binary value is correct...\n");
    int value = 0;
    for(int i = 0; i < 32; i++){
      if (reg2strReturn[i] == '1'){
        value +=1;
      }
      else if (reg2strReturn[i] == '0')
      {
        value *=2;
      }
      
    }
    printf("%i\n", value);
  /* Test2: resetAll(iRegister)

   */
    printf("\nTest2: resetAll(iRegister *)\n");
    
    
  return 0;
}
