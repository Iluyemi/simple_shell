#include "shell.h"
/**
 * _strlen - Checks the number of strings
 * @s: input string
 * Return: String length;
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * space_checker - calulating the number of tokens
 * @i: lenth of sting
 * @s: string to be checked
 * Return: number of tokens
 */
int space_checker(int i, char *s)
{
	int a = 0, n;
	char d[] = " ";

	for (n = 0; n < i; n++)
	{
		if (s[n] == d[0])
		{
			a++;
		}
	}
	return (a++);
}

/**
 * strtoking - tokenization function
 * @s: input string
 * Return: an array of strings
 */

char **strtoking(char *s)
{
	int length, No_tokens, k = 1;
	char *string;
	char d[] = " ";

	length = _strlen(s);
	No_tokens = space_checker(length, s);
/*check this process */
	char **array = malloc((No_tokens + 1) * sizeof(char *));

	string = strtok(s, d);
	array[0] = string;
	while (string != NULL)
	{
		string = strtok(NULL, d);
		array[k] = string;
		k++;
	}
	array[k] = NULL;
	return (array);
}
