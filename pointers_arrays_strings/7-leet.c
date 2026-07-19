#include "main.h"

/**
 * leet - encodes a string into 1337 leet speak using 1 if and 2 loops
 * @str: pointer to input string
 *
 * Return: pointer to the modified string
 */
char *leet(char *str)
{
	int i = 0;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (str[i] != '\0')
	{
		for (j = 0; j < 10; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = numbers[j];
			}
		}
		i++;
	}

	return (str);
}
