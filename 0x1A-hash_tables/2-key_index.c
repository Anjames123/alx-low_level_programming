#include "hash_tables.h"

/**
 * key_index - Gets the index of a key in a hash table
 *
 * @key: The key to search for
 * @size: The size of the hash table array
 *
 * Return: The index of the key/value pair in the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int index;

	hash_value = hash_djb2(key);
	index = hash_value % size;

	return (index);
}
