#include "converter.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define RADIX 3
#define RADIX_BYTES 256
#define MAX_TRIT_VALUE 1
#define MIN_TRIT_VALUE -1
#define BYTE_HASH_LENGTH 48

static const char *trytesAlphabet = "9ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int trytesTrits[27][3] = {
    { 0,  0,  0},
    { 1,  0,  0},
    {-1,  1,  0},
    { 0,  1,  0},
    { 1,  1,  0},
    {-1, -1,  1},
    { 0, -1,  1},
    { 1, -1,  1},
    {-1,  0,  1},
    { 0,  0,  1},
    { 1,  0,  1},
    {-1,  1,  1},
    { 0,  1,  1},
    { 1,  1,  1},
    {-1, -1, -1},
    { 0, -1, -1},
    { 1, -1, -1},
    {-1,  0, -1},
    { 0,  0, -1},
    { 1,  0, -1},
    {-1,  1, -1},
    { 0,  1, -1},
    { 1,  1, -1},
    {-1, -1,  0},
    { 0, -1,  0},
    { 1, -1,  0},
    {-1,  0,  0}
};

int** tritscnv(char *trytes, int len) {
    int **trits = (int **)malloc(sizeof(int **) * len);

    for (int i = 0; i < len; i++) {
        int index = (int)strchr(trytesAlphabet, (int)trytes[i]);

        int trit[3] = {
            trytesTrits[index][0], trytesTrits[index][1], trytesTrits[index][2]
        };

        trits[i * 3] = trit;
    }

    return trits;
}

char* trytescnv(int *trits, int len) {
    char *trytes = (char *)malloc(sizeof(char *) * len);

    for (int i = 0; i < len; i += 3) {
        // Iterate over all possible tryte values to find correct trit representation
        for (int j = 0; j < strlen(trytesAlphabet); j++) {
            int currentTrit[] = {
                trits[i], trits[i + 1], trits[i + 2]
            };

            if (trytesTrits[j][0] == currentTrit[0] && 
                trytesTrits[j][1] == currentTrit[1] && 
                trytesTrits[j][2] == currentTrit[2]) {

                sprintf(trytes, "%s%c", trytes, trytesAlphabet[j]);
                break;
            }
        }
    }

    return trytes;
}
