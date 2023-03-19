#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 *main - A program to print the alphabets in uppercase and then lowercase
 *       A-Z and a-z
 *Return:0
*/
int main(void)
{
char ch;
 for (ch = 'A'; ch <= 'Z'; ch++)
{
putchar(ch);
}
 for (ch = 'a'; ch <= 'z'; ch++)
{
putchar(ch);
 putchar('\n');
}
return (0);
}
