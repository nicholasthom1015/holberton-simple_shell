#include "shell_head.h"

/**
 * _strcpy - copy string pointer
 * @src: test character
 * Return: 0
 */

char *_strcpy(const char *src)
{
	int index = 0;
	char *dest;

	while (src[index])
	{
		index++;
	}
	dest = malloc(index + 1);
	if (dest == NULL)
		return (NULL);
	for (index = 0; src[index]; index++)
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}
