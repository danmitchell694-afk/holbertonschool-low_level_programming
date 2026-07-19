#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: source string pointer
 * @accept: string containing accepted match bytes
 *
 * Return: number of matching bytes in initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i;
	int match;

	while (*s != '\0')
	{
		match = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				match = 1;
				break;
			}
		}
		if (match == 0)
		{
			return (count);
		}
		count++;
		s++;
	}

	return (count);
}
