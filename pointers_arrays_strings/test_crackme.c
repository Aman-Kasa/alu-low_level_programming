/* test_crackme.c - accepts a seed and a key (C90) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
    char expected[9];
    const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    unsigned int seed;
    int pool_len = 62;
    int i;

    if (argc != 3)
    {
        printf("Usage: %s <seed> <key>\n", argv[0]);
        return (1);
    }

    seed = (unsigned int)atoi(argv[1]);
    srand(seed);
    for (i = 0; i < 8; i++)
        expected[i] = pool[rand() % pool_len];
    expected[8] = '\0';

    if (strcmp(expected, argv[2]) == 0)
    {
        printf("Tada! Congrats\n");
        return (0);
    }

    printf("Wrong password\n");
    return (1);
}

