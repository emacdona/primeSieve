#include "bits.h"

const unsigned long BITS_IN_WORD = 8 * sizeof(WORD);

void setBit(WORD* bitVec, unsigned long bitNo)
{
    int wordNo = bitNo / BITS_IN_WORD;
    int normBitNo = bitNo % BITS_IN_WORD;
    *(bitVec + wordNo) = *(bitVec + wordNo) | wordMask(normBitNo, TRUE);
}

void unSetBit(WORD* bitVec, unsigned long bitNo)
{
    int wordNo = bitNo / BITS_IN_WORD;
    int normBitNo = bitNo % BITS_IN_WORD;
    *(bitVec + wordNo) = *(bitVec + wordNo) & wordMask(normBitNo, FALSE);
}

int wordMask(int bitNo, BOOL setBit)
{
    WORD mask;

    if(setBit){
        mask = ( 1 << (BITS_IN_WORD - 1) );
        return mask >> bitNo;
    }
    else{
        return ~wordMask(bitNo, TRUE);
    }
}

BOOL bitSet(WORD* bitVec, unsigned long bitNo)
{
    int wordNo = bitNo / BITS_IN_WORD;
    int normBitNo = bitNo % BITS_IN_WORD;
    return  *(bitVec + wordNo) & wordMask(normBitNo, TRUE);
}
