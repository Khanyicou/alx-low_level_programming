#include "main.h"

/**
 * flip_bits - Counts the number of different bits between two numbers.
 * @n: The 1st unsigned long int.
 * @m: The 2nd unsigned long int.
 *
 * Return: The number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int count = 0;

while (n > 0 || m > 0)
{
if ((n & 1) != (m & 1))
count++;
n >>= 1;
m >>= 1;
}

return (count);
}
