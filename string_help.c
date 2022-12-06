#include "shell_head.h"

/**
 * _strcat - concatenates two strings
 * @dest: test character
 * @src: test character
 * Return: 0
 */

char *_strcat(char *dest, char *src)
{
	char *result = NULL;
	int index = 0, dest_len = 0, src_len = 0;

	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	result = malloc(dest_len + src_len + 1);
	for (index = 0; dest[index]; index++)
		result[index] += dest[index];

	for (index = 0; src[index]; index++)
		result[dest_len + index] = src[index];

	result[dest_len + index] = '\0';
	dest = result;
	return (result);
}
