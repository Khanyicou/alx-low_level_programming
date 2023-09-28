#include "main.h"

/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 * @n: A pointer to an unsigned long int.
 * @index: The index of the bit to clear, starting from 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask;

if (index > (sizeof(unsigned long int) * 8 - 1))
return (-1);

mask = 1UL << index;

if ((*n & mask) != 0)
*n ^= mask;

return (1);
}
