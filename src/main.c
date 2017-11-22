#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "seed_gen.h"
#include "crypto/converter.h"

void seed();
void trytes();
void trits();

int main(int argc, char **argv) {
    if (argc == 1) {
        seed();
    }

    for (int i = 0; i < argc; ++i) {
        if (strcmp("seed", argv[i]) == 0) {
            seed();
        }

        if (strcmp("trytes", argv[i]) == 0) {
            trytes();
        }

        if (strcmp("trits", argv[i]) == 0) {
            trits();
        }
    }

    return EXIT_SUCCESS;
}

void seed() {
    char seed[81];
    seed_gen(seed, 81);
    puts(seed);
}

void trytes() {
    int trit[3] = { 0, 0, 0 };
    char *tryte = trytescnv(trit, 1);

    printf("%s", tryte);
}

void trits() {
    char *tryte = "A";
    int **trit = tritscnv(tryte, strlen(tryte));

    printf("{%i, %i, %i}", trit[0][0], trit[0][1], trit[0][2]);
}
