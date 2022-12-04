#include "shell_head.h"

/**
 * _strcpy - copy string pointer
 * @dest: test character
 * @src: test character
 * Return: 0
 */

char *_strcpy(char *dest, const char *src)
{
	int index = 0;

	while (src[index])
	{
		index++;
	}
	if (dest != NULL)
		free(dest);
	dest = malloc(index+1);
	if (dest == NULL)
		return (NULL);
	for (index = 0; src[index];index++)
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}
