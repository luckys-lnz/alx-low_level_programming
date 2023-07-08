#include "main.h"
/**
 * get_endianness -checks endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
/* Create a variable 'val' and initialize it with the val 1 */
unsigned int val = 1;
/* Create a 'byte_ptr' of type 'unsigned *char',assign it mem adr of 'val' */
 unsigned char *byte_ptr = (unsigned char*) &val;
/* Check the val of the first byte pointed to by 'byte_ptr' */
if (*byte_ptr == 1)
{
/* If the val is equal to 1, it indicates little endian */
return (1);  /* Little endian */
}
else
{
/* If the val is not equal to 1, it indicates big endian */
return (0);  /* Big endian*/
}
}
