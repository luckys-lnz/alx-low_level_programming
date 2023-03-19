#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 *main -A program to output the letters of the alphabet
 *      a-z
 *Return: 0
*/
int main(void)
{
char ch;
for (ch = 'a'; ch <= 'z'; ch++)
{
putchar (ch);
}
return (0);
}
