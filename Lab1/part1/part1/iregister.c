//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"

void resetAll(iRegister *theRegister)
{
	theRegister->content &= 0x00000000;
}

void setBit(int i, iRegister *theRegister)
{
	if (0 <= i && i <= 31)
	{
		theRegister->content |= (1 << i);
	}
	else{
		printf("ERROR: Tried to call setBit(int, iRegister *) with illegal input.");
	}
}

void setAll(iRegister *theRegister)
{
	theRegister->content |= 0xFFFFFFFF;
}

int getBit(int i, iRegister *theRegister)
{
	if (i <= 31)
	{
		return ((theRegister->content & (1 << i)) >> i);
	}
	return -1;
}

void assignNibble(int i, int value, iRegister *theRegister)
{
	if (0 <= i && i < 29)
	{
		theRegister->content |= (value << i); //test this
	}
	else{
		printf("ERROR: Tried to call assignNibble(int, int, iRegister *) with illegal input.");
	}
}

// ANDREAS |
//         V
int getNibble(int i, iRegister *theRegister)
{
	if (0<= i && i < 29)
	{
		return theRegister->content & (0xF << i);
	}
	return -1;
}


char *reg2str(iRegister theRegister)
{
	
	char *returnString = malloc(32);
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

void shiftRight(int i, iRegister *theRegister)
{
	theRegister->content >>= i;
	for(int j = 0; j < i ; j++){
		resetBit(31 - j, theRegister);
	}
	
}

void shiftLeft(int i, iRegister *theRegister)
{
	theRegister->content <<= i;
	for(int j = 0; j < i ; j++){
		resetBit(j, theRegister);
	}
}

void resetBit(int i, iRegister *r)
{
	if(0 <= i && i < 32){
		r->content &= ~(1 << i);
	}
	else{
		printf("ERROR: Tried to call resetBit(int, iRegister *) with illegal input."); 
	}
	
}
