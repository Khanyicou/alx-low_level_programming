#include "hash_tables.h"

/**
 * key_index - Get the index at which a key
 * @key: The key to get the index
 * @size: The array size of the hash table.
 *
 * Return: The key index.
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
