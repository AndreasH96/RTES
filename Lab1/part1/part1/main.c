//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>


// Returns 1 if every bit is zero
int test_isAllZero(iRegister reg){
  static int status = 1;
  for(int i = 0; i < 32; i++){
    if(getBit(i, &reg) == 1){
      status = 0;
    }
  }
  return status;
}
/*returns 1 if the value of the nibble at position pos is equal to the
 value of expectedValue*/
int testNibbleValue(int pos, int expectedValue, iRegister theRegister){

  for(int i = 0 ; i < 4; i ++ ){
    int expectedValueAtBit = expectedValue & ( 1 >> i );
    int nibbleValueAtBit = theRegister.content &( 1 >> (i + pos));

    if(expectedValueAtBit != nibbleValueAtBit){
      return 0;
    };
    return 1;
  }


}

int main()
{
  iRegister r;
  char out[33];
  int testResults[10][4];

  /* Put all your test cases for the implemented functions here */
  /* Test6: getNibble(int, iRegister*)
   */
  /* Test 6.1: Assign value using assignNibble, then check if getNibble returns correctly*/
  printf("\nTest 6: getNibble(int, int , iRegister*)\n");
  resetAll(&r);
  assignNibble(5,15,&r);
  signed int returnNibble = getNibble(5, &r);
  if (testNibbleValue(5,returnNibble,r)){
    testResults[5][0] = 1;
    printf("Test 6.1 succeded\n");
  }
  else{
    testResults[5][0] = 0; 
    printf("Test 6.1 failed\n");
  }

  /* Test 6.2: Try to get Nibble outside of the register */

  returnNibble = getNibble(32, &r);

  if(returnNibble == -1){
    testResults[5][1] = 1;
    printf("Test 6.2 succeded\n");
  }
  else
  {
    testResults[5][1] = 0;
    printf("Test 6.2 failed\n");
  }
  
  /* Test 6.3: Try to give negative input for the position */

  returnNibble = 0;
  returnNibble = getNibble(-5, &r);
   if(returnNibble == -1){
    testResults[5][2] = 1;
    printf("Test 6.3 succeded\n");
  }
  else
  {
    testResults[5][2] = 0;
    printf("Test 6.3   failed\n");
  }

  /* Test 6.4: Test so that getNibble only returns 4 bits */
  resetAll(&r);
  assignNibble(5,15,&r);
  returnNibble = getNibble (5, &r);
  int amountOfBits = 0;
  
  for( int i = 0; i < (sizeof(returnNibble) * 4); i ++){
    if(getBit(i, &r)){
      amountOfBits += 1;
    }
  }
  if(amountOfBits == 4){
    testResults[5][3] = 1;
    printf("Test 6.4 succeded\n");
  }
  else {
    testResults[5][3] = 0;
    printf("Test 6.4 failed\n");    
  }

  /* Test 7: *reg2str(iRegister)*/

  r.content = 12839238;
  printf("\nTest 7: *reg2str(iRegister)\n");

  // Test 7.1: Test for correct return value length
  char *reg2strReturn = reg2str(r);
  char expected[] = "00000000110000111110100101000110";
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("%s", "Test 7.1 succeded\n");
    testResults[6][0] = 1;
  }
  // Test 7.2: Adds 1 increment content and see that the value changes
  setBit(0,&r);
  reg2strReturn = reg2str(r);
  expected[31] = '1';
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("Test 7.2 succeded\n");
    testResults[6][1] = 1;
  }
  // Test 7.3: Test with all bits cleared to 0
  resetAll(&r);
  reg2strReturn = reg2str(r);
  
  for( int i = 0; i < 32; i ++){
    expected[i] = '0';
  }
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("Test 7.3 succeded\n");
    testResults[6][2] = 1;
  }
  else{
    printf("Test 7.3 failed\n");
    testResults[6][2] = 1;
  }
  // Test 7.4: Test with all bits set to 1
  setAll(&r);
  reg2strReturn = reg2str(r);
  for( int i = 0; i < 32; i ++){
    expected[i] = '1';
  }
  if (strcmp(expected, reg2strReturn) == 0)
  {
    printf("Test 7.4 succeded\n");
    testResults[6][3] = 1;
  }

  /* Test 8: shiftRight(int, iRegister*) */  

  printf("\nTest 8: shiftRight(int,iRegister*)\n");

  /* Test 8.1: Basic shift test. */
  resetAll(&r);
  setBit(15, &r);
  shiftRight(1, &r);
  if(getBit(14, &r)){
    printf("Test 8.1 succeded\n");
    testResults[7][0] = 1;
  }
  else
  {
    printf("Test 8.1 failed\n");
    testResults[7][0] = 0;
  }
  
  /* Test 8.2: Test that a 0 is shifted from the left */
  setAll(&r);
  if(getBit(31, &r)){
    shiftRight(1,&r);

    if(~getBit(31,&r)){
      printf("Test 8.2 succeded\n");
      testResults[7][1] = 1;  
    }
    else{
    printf("Test 8.2 failed\n");
    testResults[7][1] = 0;
    }
  }
  else
  {
    printf("Test 8.2 failed, setAll(iRegister*) failed\n");
    testResults[7][1] = 0;
  }
  
  /* Test 8.3: Test that if 31 shifts are made then the register is zero*/
  setAll(&r);
  
  shiftRight(32, &r);

  if(test_isAllZero(r)){
    printf("Test 8.3 succeded\n");
    testResults[7][2] = 1;  
  }
  else{
    printf("Test 8.3 failed\n");
    testResults[7][2] = 0;
  }
  
  /* Test 8.4: Test that the bit is not in the same place after one shift*/
  resetAll(&r);

  setBit(10, &r);

  shiftRight(1, &r);

  if(~getBit(10, &r)){
    printf("Test 8.4 succeded\n");
    testResults[7][3] = 1;  
  }
  else{
    printf("Test 8.4 failed\n");
    testResults[7][3] = 0;
  }

  /* Test 9: shiftLeft(int, iRegister*) */  

  printf("\nTest 9: shiftLeft(int,iRegister*)\n");

  /* Test 9.1: Basic shift test. */
  resetAll(&r);
  setBit(15, &r);
  shiftLeft(1, &r);
  if(getBit(16, &r)){
    printf("Test 9.1 succeded\n");
    testResults[8][0] = 1;
  }
  else
  {
    printf("Test 9.1 failed\n");
    testResults[8][0] = 0;
  }
  
  /* Test 9.2: Test that a 0 is shifted from the right */
  setAll(&r);
  if(getBit(0, &r)){
    shiftLeft(1,&r);

    if(~getBit(0,&r)){
      printf("Test 9.2 succeded\n");
      testResults[8][1] = 1;  
    }
    else{
    printf("Test 9.2 failed\n");
    testResults[8][1] = 0;
    }
  }
  else
  {
    printf("Test 9.2 failed, setAll(iRegister*) failed\n");
    testResults[8][1] = 0;
  }
  
  /* Test 9.3: Test that if 31 shifts are made then the register is zero*/
  setAll(&r);
  
  shiftLeft(32, &r);

  if(test_isAllZero(r)){
    printf("Test 9.3 succeded\n");
    testResults[8][2] = 1;  
  }
  else{
    printf("Test 9.3 failed\n");
    testResults[8][2] = 0;
  }
  
  /* Test 9.4: Test that the bit is not in the same place after one shift*/
  resetAll(&r);

  setBit(10, &r);

  shiftLeft(1, &r);

  if(~getBit(10, &r)){
    printf("Test 9.4 succeded\n");
    testResults[8][3] = 1;  
  }
  else{
    printf("Test 9.4 failed\n");
    testResults[8][3] = 0;
  }

  /* Test 10: resetBit(int, iRegister*) */

  

  
  return 0;
}
