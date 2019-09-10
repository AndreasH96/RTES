//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <string.h>
#include <math.h>

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

// Returns 1 if the bit is one
int test_isBitOne(int theBit, iRegister reg){
  static int status = 0;
  if(getBit(theBit, &reg) == 1){
    status = 1;
  }
  return status;
}

// Returns 1 if every bit is zero
int test_isAllOne(iRegister reg){
  static int status = 1;
  for(int i = 0; i < 32; i++){
    if(getBit(i, &reg) == 0){
      status = 0;
    }
  }
  return status;
}


int main ()
{
  iRegister r;
  char out[33];
  int testResults[10][4]; 
  r.content = 12839238;
  /* Put all your test cases for the implemented functions here */
     
  /* Test1: resetAll(iRegister)
   */
  printf("Test 1: resetAll(iRegister *)\n");
  // Test 1.1
  printf("\nRunning Test 1.1 ...\n");
  setAll(&r);
  printf("setAll: %s\n", (char*) reg2str(r));
  resetAll(&r);
  printf("resetAll: %s\n", (char*) reg2str(r));
  if(test_isAllZero(r)){
    printf("Test 1.1 succeded!\n");
    testResults[0][0] = 1;
  }else{
    printf("Test 1.1 failed...\n");
  }
  
  // Test 1.2
  printf("\nRunning Test 1.2 ...\n");
  for(int i = 0; i < 32; i++){
    resetBit(i, &r);
  }
  printf("Reset all bits with resetBit: %s\n", (char*) reg2str(r));
  resetAll(&r);
  printf("resetAll: %s\n", (char*) reg2str(r));
  if(test_isAllZero(r)){
    printf("Test 1.2 succeded!\n");
    testResults[0][1] = 1;
  }else{
    printf("Test 1.2 failed...\n");
  }
  
  // Test 1.3
  printf("\nRunning Test 1.3 ...\n");
  setBit(0, &r);
  setBit(15, &r);
  setBit(31, &r);
  printf("Set bit 0, 15 and 31 with setBit: %s\n", (char*) reg2str(r));
  resetAll(&r);
  printf("resetAll: %s\n", (char*) reg2str(r));
  if(test_isAllZero(r)){
    printf("Test 1.3 succeded!\n");
    testResults[0][2] = 1;
  }else{
    printf("Test 1.3 failed...\n");
  }

  // Test 1.4
  printf("\nRunning Test 1.4 ...\n");
  for(int i = 0; i < 32; i++){
    if(i % 2 == 0){
      setBit(i, &r);
    }
  }
  printf("Set every other bit with setBit: %s\n", (char*) reg2str(r));
  resetAll(&r);
  printf("resetAll: %s\n", (char*) reg2str(r));
  if(test_isAllZero(r)){
    printf("Test 1.4 succeded!\n");
    testResults[0][3] = 1;
  }else{
    printf("Test 1.4 failed...\n");
  }

  // Test 2, setBit(int, iRegister)
  printf("\nTest 2: setBit(int, iRegister)\n");
  
  // Test 2.1
  printf("\nRunning Test 2.1 ... \n");
  resetAll(&r);
  printf("%s\n", reg2str(r));
  int randomBit = rand()%32;
  setBit(randomBit, &r);
  printf("%s\n", reg2str(r));
  if(test_isBitOne(randomBit, r)){
    printf("Test 2.1 succeded!\n");
    testResults[1][0];
  }else{
    printf("Test 2.1 failed...\n");
  }
  
  // Test 2.2
  printf("\nRunning Test 2.2 ... \n");
  resetAll(&r);
  printf("%s\n", reg2str(r));
  setBit(-1, &r);
  printf("%s\n", reg2str(r));
  if(test_isAllZero(r)){
    printf("Test 2.2 succeded!\n");
    testResults[1][1] = 1;
  }else{
    printf("Test 2.2 failed...\n");
  }

  // Test 2.3
  printf("\nRunning Test 2.3 ...\n");
  resetAll(&r);
  setBit(0, &r);
  setBit(15, &r);
  setBit(31, &r);
  printf("Set bit 0, 15 and 31 with setBit: %s\n", reg2str(r));
  int status = 0;
  status += test_isBitOne(0, r);
  status += test_isBitOne(15, r);
  status += test_isBitOne(31, r);
  if(status == 3){
    printf("Test 2.3 succeded!\n");
    testResults[1][2] = 1;
  }else{
    printf("Test 2.3 failed...\n");
  }

  // Test 2.4
  printf("\nRunning Test 2.4 ...\n");
  resetAll(&r);
  for(int i = 0; i < 32; i++){
    if(i % 2 == 0){
      setBit(i, &r);
    }
  }
  printf("Set every other bit with setBit: %s\n", (char*) reg2str(r));
  status = 0;
  for(int i = 0; i < 32; i++){
    if(i % 2 == 0){
      status += test_isBitOne(i, r);
    }
  }
  if(status == 16){
    printf("Test 2.4 succeded!\n");
    testResults[1][3] = 1;
  }else{
    printf("Test 2.4 failed...\n");
  }
  
  // Test 3, setAll(iRegister)
  printf("\nTest 3: setAll(iRegister)\n");

  // Test 3.1
  printf("\nRunning Test 3.1 ...\n");
  resetAll(&r);
  printf("%s\n", reg2str(r));
  setAll(&r);
  if(test_isAllOne(r)){
    printf("Test 3.1 succeded!\n");
    testResults[2][0] = 1;
  }else{
    printf("Test 3.1 failed...\n");
  }

  // Test 3.2
  printf("\nRunning Test 3.2 ...\n");
  resetAll(&r);
  printf("%s\n", reg2str(r));
  setBit(rand()%32, &r);
  setAll(&r);
  printf("%s\n", reg2str(r));
  if(test_isAllOne(r)){
    printf("Test 3.2 succeded!\n");
    testResults[2][1] = 1;
  }else{
    printf("Test 3.2 failed...\n");
  }

  // Test 3.3
  printf("\nRunning Test 3.3 ...\n");
  setAll(&r);
  resetBit(0, &r);
  resetBit(15, &r);
  resetBit(31, &r);
  printf("Reset bit 0, 15 and 31 with resetBit: %s\n", (char*) reg2str(r));
  setAll(&r);
  printf("%s\n", reg2str(r));
  if(test_isAllOne(r)){
    printf("Test 3.3 succeded!\n");
    testResults[2][2] = 1;
  }else{
    printf("Test 3.3 failed...\n");
  }

  // Test 3.4
  printf("\nRunning Test 3.4 ...\n");
  resetAll(&r);
  for(int i = 0; i < 32; i++){
    if(i % 2 == 0){
      setBit(i, &r);
    }
  }
  printf("%s\n", reg2str(r));
  setAll(&r);
  printf("%s\n", reg2str(r));
  if(test_isAllOne(r)){
    printf("Test 3.4 succeded!\n");
    testResults[2][3] = 1;
  }else{
    printf("Test 3.4 failed...\n");
  }

  // Test getBit(i, iRegister)
  printf("\nTest 4: getBit(1, iRegister)\n");
  printf("\nRunning Test 4.1 ...\n");
  // Test 4.1
  resetAll(&r);
  if(getBit(rand()%32, &r) == 0){
    printf("Test 4.1 succeded!\n");
    testResults[3][0] = 1;
  }else{
    printf("Test 4.1 failed...\n");
  }

  // Test 4.2
  printf("\nRunning Test 4.2 ...\n");
  resetAll(&r);
  randomBit = rand()%32;
  setBit(randomBit, &r);
  if(getBit(randomBit, &r) == 1){
    printf("Test 4.2 succeded!\n");
    testResults[3][1] = 1;
  }else{
    printf("Test 4.2 failed...\n");
  }

  // Test 4.3
  printf("\nRunning Test 4.3 ...\n");
  resetAll(&r);
  if(getBit(33, &r) == -1){
    printf("Test 4.3 succeded!\n");
    testResults[3][2] = 1;
  }else{
    printf("Test 4.3 failed...\n");
  }

  // Test 4.4
  printf("\nRunning Test 4.4 ...\n");
  resetAll(&r);
  if(getBit(33, &r) == -1){
    printf("Test 4.4 succeded!\n");
    testResults[3][3] = 1;
  }else{
    printf("Test 4.4 failed...\n");
  }

  // Test assignNibble(i, val, iRegister)
  printf("\nTest 5: assignNibble(i, val, iRegister)\n");
  
  // Test 5.1
  printf("\nRunning Test 5.1 ...\n");
  resetAll(&r);
  printf("%s\n", reg2str(r));
  for(int i = 1; i < 9; i++){
    assignNibble(i, 1, &r);
  }
  printf("%s\n", reg2str(r));
  if(test_isAllOne(r)){
    printf("Test 5.1 succeded!\n");
    testResults[4][0] = 1;
  }else{
    printf("Test 5.1 failed...\n");
  }

  // Test 5.2
  printf("\nRunning Test 5.2 ...\n");
  setAll(&r);
  printf("%s\n", reg2str(r));
  for(int i = 1; i < 9; i++){
    assignNibble(i, 0, &r);
  }
  printf("%s\n", reg2str(r));
  if(test_isAllZero(r)){
    printf("Test 5.2 succeded!\n");
    testResults[4][1] = 1;
  }else{
    printf("Test 5.2 failed...\n");
  }

  printf("\nRunning Test 5.3 ...\n");
  resetAll(&r);
  assignNibble(9, 1, &r);
  if(test_isAllZero(r)){
    printf("Test 5.3 succeded!\n");
    testResults[4][2] = 1;
  }else{
    printf("Test 5.3 failed...\n");
  }

  printf("\nRunning Test 5.4 ...\n");
  resetAll(&r);
  assignNibble(-1, 1, &r);
  if(test_isAllZero(r)){
    printf("Test 5.4 succeded!\n");
    testResults[4][3] = 1;
  }else{
    printf("Test 5.4 failed...\n");
  }
  


  return 0;
}
