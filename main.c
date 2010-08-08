//http://zmievski.org/2010/08/the-prime-that-wasnt
#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

int main(int argc, char* argv[])
{
    if(argc != 2){
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int number = atoi(argv[1]);
    number += 1; //we're zero indexed; this will let them test the number they entered

    int numWords =  (number / (8*sizeof(WORD)))          //number of full words we'll need...
                    + ((number % (8*sizeof(WORD)))?1:0); //...plus perhaps one more word to hold any bits that
                                                         //are left

    //printf("%i %lu-byte word(s) contain(s) at least %i bits.\n",  numWords, sizeof(WORD), number);

    WORD* bitVec = (WORD*) calloc(numWords, sizeof(WORD));

    if(bitVec == NULL){
        printf("Error allocating memory.\n");
        return 1;
    }

    WORD *w;

    //Initialze all the bits to '1'; i.e. start off by assuming everything is prime
    for(w=bitVec; w<bitVec+numWords; w++)
        *w = ~0;

    int i, factor=2;

    while(factor < (number/2 + 1)){ //Only have to test the first half of the possible factors.
                                    //Trust me. There's a proof somewhere ;-)
        for(i=0; i < number; i+=factor){
            if(i < number && i != factor){
                unSetBit(bitVec, i);
            }
        }
        factor++;
    }

    for(i=2;i<number;i++){
        if(bitSet(bitVec, i)){
            printf("%i is prime.\n", i);
        }
    }

    free(bitVec);
    return 0;
}
