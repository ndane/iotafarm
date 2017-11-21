#include "seed_gen.h"

#include <stdio.h>

int main(int argc, char **argv) {
    char seed[81];
    seed_gen(seed, 81);
    printf("%s\n", seed);
    return 0;
}