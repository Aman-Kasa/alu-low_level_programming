/* 101-keygen.c
 * Simple key generator for 101-crackme-style programs.
 * Uses srand/time/getpid to seed and prints an 8-char password.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
	const char *pool = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	                   "abcdefghijklmnopqrstuvwxyz"
	                   "0123456789";
	const int pool_len = 62; /* 26 + 26 + 10 */
	const int passlen = 8;   /* change length if needed */
	int i;

	/* seed with time + pid to reduce collisions */
	srand((unsigned int)(time(NULL) ^ (getpid() << 16)));

	for (i = 0; i < passlen; i++)
		putchar(pool[rand() % pool_len]);
	putchar('\n');

	return (0);
}
