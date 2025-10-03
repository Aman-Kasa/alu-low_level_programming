/* 101-keygen.c - seed-aware keygen (C90) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    unsigned int seed;
    int pool_len = 62;
    char key[9];
    int i;

    if (argc == 2)
        seed = (unsigned int)atoi(argv[1]);
    else
        seed = (unsigned int)time(NULL);

    srand(seed);
    for (i = 0; i < 8; i++)
        key[i] = pool[rand() % pool_len];
    key[8] = '\0';
    printf("%s\n", key);

    return (0);
}

