#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: target string body pointer
 * @needle: substring sequence pointer to locate
 *
 * Return: pointer to start of located substring, or NULL if missing
 */
char *_strstr(char *haystack, char *needle)
{
	char *h;
	char *n;

	if (*needle == '\0')
	{
		return (haystack);
	}

	while (*haystack != '\0')
	{
		h = haystack;
		n = needle;

		while (*h != '\0' && *n != '\0' && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}
