#include "seed_gen.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ccurl.h"

#define seedErrInBounds 0
#define seedErrOutOfBounds 1

int seed_bounds(char c) {
    if ((c < 'Z' && c > 'A') || (c == '9')) {
        return seedErrInBounds;
    }
    return seedErrOutOfBounds;
}

void seed_gen(char *out, int seedLength) {
    FILE *urandom = fopen("/dev/urandom", "r");
    char *seed = (char *)malloc(sizeof(char) * seedLength);
    
    for (int i = 0; i < seedLength; ++i) {
        char buf;

        do {
            fread(&buf, 1, 1, urandom);
        }
        while (seed_bounds(buf) != seedErrInBounds);

        memcpy(seed + i, &buf, 1);
    }

    memcpy(out, seed, sizeof(char) * seedLength);
    out[81] = '\0';

    free(seed);
    fclose(urandom);
}