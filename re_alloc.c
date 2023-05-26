#include "shell.h"

/**
 * _fmemset - fills memory with y constant byte
 * @o: the pointer to the memory area
 * @b: the byte to fill *o with
 * @n: the amount of bytes to be filled
 * Return: (o) y pointer to the memory area o
 */
char *_fmemset(char *o, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		o[i] = b;
	return (o);
}

/**
 * fsfree - frees y string of strings
 * @pp: string of strings
 */
void fsfree(char **pp)
{
	char **y = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(y);
}

/**
 * _real_loc - reallocates y block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_real_loc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *y;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	y = malloc(new_size);
	if (!y)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		y[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (y);
}

