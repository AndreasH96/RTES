//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.
//
//  Assignment made by Karl-Johan Djervbrant and Andreas Häggström

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
/** @brief gets the i'th nibble of register
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return int
 * 
 *  Pre-condition: 0 < i <= 8, and iRegister != Null
 * 
 *  Post-condition: after getNible(i, val, &r), it should return the i'th nibble in the register
 *  properties: 
 *  after getNibble(i, val, &r), the return value should be equal to the value of the nibble in the regiset
 *  
 *  test-cases: 
 *  Case 1: 
 *  first do resetAll(&r),
 *  assignNibble(5, 15 ,&r)
 * printf("%s", reg2str(r))
 *      getNibble(5, &r)
 *  test_NibbleValue(5, nibble, r) 
 *  
 *  Case 2:
 *  first do returnNibble = getNibble(9, &r)
 *  then test if returnNibble == -1
 *  if not, then test failed
 *  
 *  Case 3:
 *  first do returnNibble = getNibble(-1, &r)
 *  then test if returnNibble == -1
 *  if not, then test failed
 * 
 *  Case 4:
 *  first do setAll(&r)
 *  then do returnNibble = getNibble(5, &r)
 *  then through masking test if the amounts of bits
 *  set to 1 in returnNibble equals 4
 * 
 */
int getNibble(int, iRegister *);


/** returns a pointer to an array of 32 characters, with each character 
 *  representing the corresponding bit of the iRegister, i.e., if the bit is set,
 *  then the character is "1" (ASCII char with code 49), or otherwise is "0" 
 *  (ASCII char with code 48)
 */
/** @brief gets the 32bit representation of the register
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return string
 * 
 *  Pre-condition: iRegister != Null
 * 
 *  Post-condition: after reg2str(r), the register is unchanged
 *  properties: 
 *  after reg2str(r), the return value should be a bit representation of the value in the register
 *  
 *  test-cases: 
 *  Case 1: 
 *  first set the register to a arbitrary number
 *  create a string that shows the expected return value
 *  then do reg2str(r)
 *  finally compare the return value to the expected return value
 *  
 *  Case 2:
 *  first add 1 to the previous value of the register
 *  also increment the expected value by 1
 *  then do reg2str(r) 
 *  finally see so that the return value now still matches the expected
 *  
 *  Case 3:
 *  first do resetAll(&r)
 *  then do reg2str(r)
 *  finally see so that the return value solely consists of zeroes
 * 
 *  Case 4:
 *  first do setAll(&r)
 *  then do reg2str(r)
 *  finally see so that the return value solely conists of ones
 * 
 */
char *reg2str(iRegister);


/** shifts all the bits of the iRegister to the right by n palces (appends 0 
 *  from the left)
 */
/** @brief shift the content of the register for the amount of places specified
 * 
 *  @param i is the amount of places to shift the register
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition:  i > 0 and iRegister != Null
 * 
 *  Post-condition: after shiftRight(int i ,iRegister *r), the content in the register should have been shifted
 *  for i amount of places. 
 *  properties: 
 *  shiftRight(int i, iRegister *r) should not alter the register in any other way. It also 
 *  adds a 0 from the left for each place shifted.
 *  
 *  test-cases: 
 *  Case 1: 
 *  first set a bit in the register,
 *  then shift by one place and check so that the shift was 
 *  executed properly by using reg2str(r) and getBit(int i ,&r)
 * 
 * 
 *  Case 2:
 *  first set all bits using setAll(&r)
 *  then shift by one step
 *  check that the function added a 0 from the left
 *  using reg2str() and getBit(int i ,&r)
 * 
 *  Case 3:
 *  first do setAll(&r)
 *  then shift by 31 steps
 *  check so that all bits now are zero
 *  by using reg2str(r) and test_isAllZero(r)
 * 
 *  Case 4:
 * first set a bit in the register by using setBit(int i, &r)
 * then shift by one position
 * finally check so that the value in the position where the bit was set
 * now contains a 0 
 * 
 */
void shiftRight(int, iRegister *);


/** shifts all the bits of the iRegister to the left by n palces (appends 0 
 *  from the right)
 */
/** @brief shift the content of the register for the amount of places specified
 * 
 *  @param i is the amount of places to shift the register
 * 
 *  @param r is a pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition:  i > 0 and iRegister != Null
 * 
 *  Post-condition: after shiftLeft(int i ,iRegister *r), the content in the register should have been shifted
 *  for i amount of places. 
 *  properties: 
 *  shiftLeft(int i, iRegister *r) should not alter the register in any other way. It also 
 *  adds a 0 from the right for each place shifted.
 *  
 *  test-cases: 
 *  Case 1: 
 *  first set a bit in the register,
 *  then shift by one place and check so that the shift was 
 *  executed properly by using reg2str(r) and getBit(int i ,&r)
 * 
 * 
 *  Case 2:
 *  first set all bits using setAll(&r)
 *  then shift by one step
 *  check that the function added a 0 from the right
 *  using reg2str() and getBit(int i ,&r)
 * 
 *  Case 3:
 *  first do setAll(&r)
 *  then shift by 31 steps
 *  check so that all bits now are zero
 *  by using reg2str(r) and test_isAllZero(r)
 * 
 *  Case 4:
 * first set a bit in the register by using setBit(int i, &r)
 * then shift by one position
 * finally check so that the value in the position where the bit was set
 * now contains a 0 
 * 
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
 *  Case 1: 
 *  first set all bits
 *  then reset a random bit
 *  check so that it was reset by using
 *  reg2str(r) and getBit(int i, &r)
 * 
 *  Case 2:
 *  first set all bits
 *  then try to reset with a invalid input
 *  check so that all bits still are set using
 *  test_isAllOne(r)
 * 
 *  Case 3:
 *  first set all bits
 *  then reset bit 0, 15, 31
 *  then use test_isBitOne(int i ,r)
 *  and reg2str(r) to check so that those bits are reset
 * 
 *  Case 4:
 *  first set all bits
 *  then reset every other bit through a for loop
 *  then check so that the bits have been correctly reset
 *  by using test_isBitOne(int i, r) and reg2str(r)
 */
void resetBit(int, iRegister *);

#endif