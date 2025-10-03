/* 101-keygen_time_pid.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int poollen = 62, i;

    srand((unsigned int)(time(NULL) ^ (getpid() << 16)));
    for (i = 0; i < 8; i++)
        putchar(pool[rand() % poollen]);
    putchar('\n');
    return 0;
}

