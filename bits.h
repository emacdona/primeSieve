#ifndef __bits_h__
#define __bits_h__

typedef unsigned int WORD;
typedef int BOOL;

#define TRUE 1
#define FALSE 0

void setBit(WORD* bitVec, unsigned long bitNo);
void unSetBit(WORD* bitVec, unsigned long bitNo);
int wordMask(int bitNo, BOOL setBit);
BOOL bitSet(WORD* bitVec, unsigned long bitNo);

#endif
