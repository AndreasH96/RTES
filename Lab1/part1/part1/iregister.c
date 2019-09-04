//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.
 
#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"


void resetAll(iRegister *theRegister){
	theRegister->content &= 0x00000000;
}

void setBit(int i, iRegister *theRegister){
	if( i <= 31){
		theRegister-> content |= (1 << i);
	}
}

void setAll(iRegister *theRegister){
	theRegister->content |= 0xFFFFFFFF;
}

int getBit(int i , iRegister *theRegister){
	if ( i <= 31 ){
		return  theRegister->content & (1 << i);
	}
	return -1;
}

void assignNibble(int i ,int value, iRegister *theRegister){
	if(i < 29){
		theRegister->content |= (value << i ); //test this
	}
}

int getNibble(int i, iRegister *theRegister){
	if (i < 29){
		return theRegister->content & (0xF << i);
	}

	return -1;
}

char *reg2str(iRegister theRegister){
	char[32] returnString;
	for(int i = 0 ; i < sizeof(theRegister.content); i++){
		returnString[i] = (char) theRegister.content[i];
	}
	return *returnString;
}

void shiftRight(int i, iRegister *theRegister){
	theRegister->content >> i;
}

void shiftLeft(int i, iRegister *theRegister){
	theRegister->content << i;
}

void resetBit(int i, iRegister *r) {
	r->content &= ~(1 << i);
}
