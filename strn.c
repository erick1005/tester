#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @o: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *o)
{
	int i = 0;

	if (!o)
		return (0);

	while (*o++)
		i++;
	return (i);
}

/**
 * _stricmp - performs lexicogarphic comparison of two strangs.
 * @o: the first strang
 * @s2: the second strang
 *
 * Return: negative if o < s2, positive if o > s2, zero if o == s2
 */
int _stricmp(char *o, char *s2)
{
	while (*o && *s2)
	{
		if (*o != *s2)
			return (*o - *s2);
		o++;
		s2++;
	}
	if (*o == *s2)
		return (0);
	else
		return (*o < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strngcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strngcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

