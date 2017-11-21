#include "seed_gen.h"

#include <stdio.h>
#include <string.h>

void seed();

int main(int argc, char **argv) {
    if (argc == 1) {
        seed();
    }

    for (int i = 0; i < argc; ++i) {
        if (strcmp("seed", argv[i]) == 0) {
            seed();
        }
    }

    return 0;
}

void seed() {
    char seed[81];
    seed_gen(seed, 81);
    puts(seed);
}