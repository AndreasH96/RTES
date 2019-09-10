//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#ifndef lab0_iregister_h
#define lab0_iregister_h

/**
 *  iRegister
 *  An iRegister is a structure which represents an 32-bit register and
 *  is equipped with standard operations to modify and display them.
 */ 
typedef struct{
    int content;
} iRegister;

/**
 *  Bellow you find the declarations for the functions to modify and display the
 *  memory content of a iRegister data structure. Before each declaration, a brief 
 *  description about what the function shall do is given. 
 *  Later in this file, the documentation for the resetBit function is given. 
 *  Students should follow that format.
 */ 

/** @brief Resets all the bits of the iRegister (to 0)
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: after reset(r) all the bits should be reset to 0.
 *  properties: 
 *  after resetBit(r),  getBit(i, r) = 0 (0<= i < 32)
 *  for 0<= i < 32
 *      getBit(i,r) == 0
 *  
 *  test-cases: 
 *  Case 1: 
 *  first do setAll(&r),
 *  printf("%s", reg2str(r))
 *  then do resetAll(&r) 
 *  printf("%s",reg2str(r)) 
 *  test_isAllZero(r)
 * 
 *  Case 2:
 *  first do resetBit(i, r) 0<= i < 32
 *  printf("%s", reg2str(r))
 *  then do resetAll(&r)
 *  print("%s", reg2str(r))
 *  test_isAllZero(r)
 * 
 *  Case 3:
 *  first do setBit(i, r) i = 0, 15, 31
 *  printf("%s", reg2str(r))
 *  then do resetAll(&r)
 *  printf("%s", reg2str(r))
 *  test_isAllZero(r)
 * 
 *  Case 4:
 *  first do for (0<= i < 32) i++
 *      if(i % 2 == 0)
 *          setBit(i, r)
 *  printf("%s", reg2str(r))
 *  then do resetAll(r)
 *  printf("%s", reg2str(r))
 *  test_isAllZero(r)
 * 
 */

void resetAll(iRegister *);

/** @brief sets the i'th bit of the iRegister (to 1)
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after setBit(i, &r), bit i should be set to 1.
 *  properties: 
 *  after setBit(i, &r),  getBit(i, &r) = 1
 *  
 *  test-cases: 
 *  Case 1: 
 *  first do resetAll(&r),
 *  printf("%s", reg2str(r))
 *  then do setBit(i, &r) 
 *  printf("%s",reg2str(r)) 
 *  test_isBitOne(i, r)
 * 
 *  Case 2:
 *  first do resetAll(&r)
 *  printf("%s", reg2str(r))
 *  then do setBit(-1, &r)
 *  print("%s", reg2str(r))
 *  test_isAllZero(i, r)
 * 
 *  Case 3:
 *  first do setBit(i, r) i = 0, 15, 31
 *  printf("%s", reg2str(r))
 *  then do resetAll(&r)
 *  printf("%s", reg2str(r))
 *  test_isBitOne(i, r)
 * 
 *  Case 4:
 *  first do for (0<= i < 32) i++
 *      if(i % 2 == 0)
 *          setBit(i, r)
 *  printf("%s", reg2str(r))
 *  test_isBitOne(i, r)
 * 
 */
void setBit(int, iRegister *);

/** @brief Sets all the bits of the iRegister (to 1)
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: after setAll(r) all the bits should be set to 1.
 *  properties: 
 *  after setAll(r),  getBit(i, r) = 1 (0<= i < 32)
 *  for 0<= i < 32
 *      getBit(i,r) == 1
 *  
 *  test-cases: 
 *  Case 1: 
 *  first do resetAll(&r),
 *  printf("%s", reg2str(r))
 *  then do setAll(&r) 
 *  printf("%s",reg2str(r)) 
 *  test_isAllOne(r)
 * 
 *  Case 2:
 *  first do resetAll(&r)
 *  printf("%s", reg2str(r))
 *  then do setBit(rand()%32, &r)
 *              setAll(&r)
 *  test_isAllOne(r)
 * 
 *  Case 3:
 *  setAll(&r)
 *  first do resetBit(i, r) i = 0, 15, 31
 *  printf("%s", reg2str(r))
 *  then do setAll(&r)
 *  printf("%s", reg2str(r))
 *  test_isAllOne(r)
 * 
 *  Case 4:
 *  first do 
 *  resetAll(&r)
 *  for (0<= i < 32) i++
 *      if(i % 2 == 0)
 *          setBit(i, r)
 *  printf("%s", reg2str(r))
 *  then do setAll(r)
 *  printf("%s", reg2str(r))
 *  test_isAllOne(r)
 * 
 */

void setAll(iRegister *);


/** 
 */

/** @brief returns the i'th bit of the iRegister as an integer (1 if it is set, or 0 otherwise)
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after getBit(i, &r), it should return the bit in the register without changeing the value.
 *  properties: 
 *  after setBit(i, &r), getBit(i, &r) = 1
 *  after resetBit(i, &r), getBit(i, &r) = 0
 *  
 *  test-cases: 
 *  Case 1: 
 *  first do resetAll(&r),
 *  printf("%s", reg2str(r))
 *  test getBit(rand()%32, &r) == 0 
 *  
 *  Case 2:
 *  first do resetAll(&r)
 *  printf("%s", reg2str(r))
 *  test setBit(rand()%32, &r) == 1
 *  
 *  Case 3:
 *  first do resetAll(&r)
 *  test getBit(33, &r) == -1
 *  
 *  Case 4:
 *  first do resetAll(&r)
 *  test getBit(-1, &r) == -1
 *  
 */

int getBit(int, iRegister *);


/** set the first (for pos=1) or the second (for pos=2) four bits of iRegsiter
 */
/** @brief sets the i'th nibble to value val to register
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return int
 * 
 *  Pre-condition: 0 < i <= 8, val = 0 or = 1 and iRegister != Null
 * 
 *  Post-condition: after assignNibble(i, val, &r), it should set the i'th nibble in the register to the value val.
 *  properties: 
 *  after assingNibble(i, val, &r), for every bit in i'th nibble getBit(i, &r) = val
 *  
 *  test-cases: 
 *  Case 1: 
 *  first do resetAll(&r),
 *  printf("%s", reg2str(r))
 *  for 0< i < 9; i++ 
 *      assignNibble(i, 1, &r)
 *  test_isAllOne(&r) 
 *  
 *  Case 2:
 *  first do setAll(&r)
 *  printf("%s", reg2str(r))
 *  for 0< i < 9; i++ 
 *      assignNibble(i, 0, &r)
 *  test_isAllZero(&r) 
 *  
 *  Case 3:
 *  first do resetAll(&r)
 *  test if assignNibble(9, 1, &r) prints error message
 *  test_isAllZero(&r)
 *  
 *  Case 4:
 *  first do resetAll(&r)
 *  test assignNibble(-1, 1, &r) print error message
 *  test_isAllZero(&r)
 * 
 */
void assignNibble(int, int, iRegister *);


/** get the first (for pos=1) or the second (for pos=2) four bits of iRegsiter
 */
int getNibble(int, iRegister *);


/** returns a pointer to an array of 32 characters, with each character 
 *  representing the corresponding bit of the iRegister, i.e., if the bit is set,
 *  then the character is "1" (ASCII char with code 49), or otherwise is "0" 
 *  (ASCII char with code 48)
 */
char *reg2str(iRegister);


/** shifts all the bits of the iRegister to the right by n palces (appends 0 
 *  from the left)
 */
void shiftRight(int, iRegister *);


/** shifts all the bits of the iRegister to the left by n palces (appends 0 
 *  from the right)
 */
void shiftLeft(int, iRegister *);


/** @brief Resets the i'th bit of the iRegister (to 0)
 *
 *  @param i Is i'th bit of the iRegister to be reset
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after reset(i, r) the i'th bit of iRegister is 0, all other 
 *  bits remain unchanged
 *  properties: 
 *  after resetBit(i, r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then  
 *    getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 *  test-cases: 
 *  1,2,3. Allocate memory to an iRegister r
 *  first do resetAll(&r),
 *  then set the i'th bit of &x by setBit(i, &r) for i = 0, 15 and 23 and then
 *  display the result after each and every call by 
 *    printf("%s",reg2str(r)) 
 */
void resetBit(int, iRegister *);

#endif