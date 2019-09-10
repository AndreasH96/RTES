//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>

int main()
{
  iRegister r;
  char out[33];
  int testResults[10][4];

  /* Put all your test cases for the implemented functions here */
  /* Test2: resetAll(iRegister)

   */

  /* Test 6: *reg2str(iRegister)
   */

  r.content = 12839238;
  printf("\nTest 6: *reg2str(iRegister)\n");

  // Test 6.1: Test for correct return value length
  char *reg2strReturn = reg2str(r);
  char expected[] = "00000000110000111110100101000110";
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("%s", "Test 6.1 succeded\n");
    testResults[5][0] = 1;
  }
  // Test 6.2: Adds 1 increment content and see that the value changes
  setBit(0,&r);
  reg2strReturn = reg2str(r);
  expected[31] = '1';
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("Test 6.2 succeded\n");
    testResults[5][1] = 1;
  }
  // Test 6.3: Test with all bits cleared to 0
  resetAll(&r);
  reg2strReturn = reg2str(r);
  
  for( int i = 0; i < 32; i ++){
    expected[i] = '0';
  }
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("Test 6.3 succeded\n");
    testResults[5][2] = 1;
  }
  // Test 6.4: Test with all bits set to 1
  setAll(&r);
  reg2strReturn = reg2str(r);
  for( int i = 0; i < 32; i ++){
    expected[i] = '1';
  }
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("Test 6.4 succeded\n");
    testResults[5][3] = 1;
  }
  return 0;
}
