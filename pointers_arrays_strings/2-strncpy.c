#include "main.h"

/**
 * _strncpy - copies a string exactly like strncpy
 * @dest: destination buffer pointer
 * @src: source string pointer
 * @n: number of characters to copy
 *
 * Return: pointer to the destination buffer dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
