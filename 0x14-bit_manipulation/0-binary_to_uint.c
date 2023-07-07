#include <stdlib.h>
#include "main.h"

/**
 * binary_to_uint - Converts from binary to unsigned integer.
 * @b: A pointer to the bit string.
 *
 * Return: The unsigned integer (success) & 0 (fails).
 */
unsigned int binary_to_uint(const char *b)
{
  unsigned int total = 0, i = 0;
  int index = 0, length_b = 0;

  if (b == NULL)
    return (0);

  /*get length of string*/
  while (b[index] != '\0')
  {
    length_b++;
    index++;
  }

  while (length_b--)
  {
    if (b[length_b] < 48 || b[length_b] > 49)
      return (0);

    if (b[length_b] == 49)
    {
      total += 1 << i;
    }
    i++;
  }
  return (total);
}
