//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.
//
//  Assignment made by Karl-Johan Djervbrant and Andreas Häggström

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"

// iRegister is 32-bits, we "and" the register with an empty register to set all bits to 0.
void resetAll(iRegister *theRegister)
{
	theRegister->content = 0x00000000;
}

// Leftshift a 1, i times to set the bit. If the pre-condition 0<= i < 32 is violated it prints an error message
void setBit(int i, iRegister *theRegister)
{
	if (0 <= i && i <= 31)
	{
		theRegister->content |= (1 << i);
	}
	else{
		#if __x86_64__
			printf("ERROR: Tried to call setBit(int, iRegister *) with illegal input.\n");
		#endif
	}
}

// iRegister is 32-bits, we "or" the register with a "full" register to set all bits to 1.
void setAll(iRegister *theRegister)
{
	theRegister->content = 0xFFFFFFFF;
}

// We mask out the corresponding bit, but to get it as decimal value 1, we shift it back i times. If the pre-condition 0<= i < 32 is violated it prints an error message.
int getBit(int i, iRegister *theRegister)
{
	if (0 <= i && i <= 31)
	{
		return ((unsigned int) (theRegister->content & (1 << i)) >> i);
	}
	#if __x86_64__
		printf("%s\n","ERROR: Tried to call getBit(int i, iRegister *theRegister) with illegal input.\n");
	#endif
	return -1;
}

// First we make sure the i value is in the correct value range, then calculate at which bit the nibble starts at, then either set it to ones or zeros.
void assignNibble(int i, int value, iRegister *theRegister)
{
	if (0 < i && i <= 8){		
		i = (i-1)*4; // Position of first bit in each nibble
		for(int j = 0; j < 4; j++){
			if(value == 0){
				theRegister->content &= ~(1 << i+j); // "and" with inverted ones to set 0
			}else{
				theRegister->content |= (1 << i+j); // "or" with ones to set bits 
			}
		}
	}
	else{
		#if __x86_64__
			printf("ERROR: Tried to call assignNibble(int, int, iRegister *) with illegal input.\n");
		#endif
		}
}

// First we make sure the i value is in the correct value range, then calculate at which bit the nibble starts at, then mask out the bits with a nibble of ones
int getNibble(int i, iRegister *theRegister)
{
	if (0 < i && i <= 8){  // There's 8 nibbles
		i = (i-1)*4; // Position of first bit in each nibble
		return theRegister->content & (0xF << i);
	}
	return -1;
}

// First we allocate memory for the string, then for every bit in the register we mask out the bit and stores the corresponding ascii value in the string.
char *reg2str(iRegister theRegister)
{	
	char *returnString = calloc(33, sizeof(char));
	for (int i = 0; i < 32; i++)
	{
		if (theRegister.content & (1 << i))
		{
			returnString[31 - i] = 0x31;
		}
		else if (!(theRegister.content & (1 << i)))
		{
			returnString[31 - i] = 0x30;
		}
	}
	return returnString;
}

// shifts the register to the right i times, then for every rightshift we reset the each "new" incomming bit from the left
void shiftRight(int i, iRegister *theRegister)
{
	if(i%32 == 0){
		resetAll(theRegister);
	}
	else{
		theRegister->content >>= i;
	}
}

// Same as with shift right bit now with leftshift
void shiftLeft(int i, iRegister *theRegister)
{
	if(i%32 == 0){
		resetAll(theRegister);
	}
	else{
		theRegister->content <<= i;
	}
}

// Leftshift an inverted 1, i times to reset the bit. If the pre-condition 0<= i < 32 is violated it prints an error message.
void resetBit(int i, iRegister *r)
{
	if(0 <= i && i < 32){
		r->content &= ~(1 << i);
	}
	else{
		#if __x86_64__
			printf("ERROR: Tried to call resetBit(int, iRegister *) with illegal input."); 
		#endif
	}
}
