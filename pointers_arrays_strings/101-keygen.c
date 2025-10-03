/* brute-keygen.c - generate candidate for each seed in window */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void make_key(unsigned int seed, char *out) {
    const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int poollen = 62, i;
    srand(seed);
    for (i = 0; i < 8; i++)
        out[i] = pool[rand() % poollen];
    out[8] = '\0';
}

int main(void) {
    unsigned int now = (unsigned int)time(NULL);
    char key[9];
    int offset;
    for (offset = -5; offset <= 5; offset++) {
        make_key(now + offset, key);
        printf("seed %u -> %s\n", now + offset, key);
    }
    return 0;
}

