/* 101-keygen.c - key generator that accepts optional seed (C90) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    unsigned int seed;
    int pool_len = 62;
    int i;

    if (argc == 2)
        seed = (unsigned int)atoi(argv[1]);
    else
        seed = (unsigned int)time(NULL);

    printf("Seed: %u\n", seed);
    srand(seed);

    for (i = 0; i < 8; i++)
        putchar(pool[rand() % pool_len]);
    putchar('\n');

    return (0);
}

