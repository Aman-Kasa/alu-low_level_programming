/* 101-keygen_time_alnum.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int poollen = 62;
    int i;

    srand((unsigned int)time(NULL));
    for (i = 0; i < 8; i++)
        putchar(pool[rand() % poollen]);
    putchar('\n');
    return 0;
}

