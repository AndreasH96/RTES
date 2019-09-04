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
	if (i <= 31)
	{
		theRegister->content |= (1 << i);
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
		return theRegister->content & (1 << i);
	}
	return -1;
}

void assignNibble(int i, int value, iRegister *theRegister)
{
	if (i < 29)
	{
		theRegister->content |= (value << i); //test this
	}
}

int getNibble(int i, iRegister *theRegister)
{
	if (i < 29)
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
	int temp = theRegister->content & 1;
	theRegister->content >>= i;
	if (temp)
	{
		setBit(31, theRegister);
	}
	else if (!temp)
	{
		resetBit(31, theRegister);
	}
}

void shiftLeft(int i, iRegister *theRegister)
{
	int temp = theRegister->content & (1 << 31);
	theRegister->content <<= i;
	if (temp)
	{
		setBit(0, theRegister);
	}
	else if (!temp)
	{
		resetBit(0, theRegister);
	}
}

void resetBit(int i, iRegister *r)
{
	r->content &= ~(1 << i);
}
