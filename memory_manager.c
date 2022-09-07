#include "shell.h"

void *_realloc(void *ptr, int oldsize, int newsize)
{
	void *tmp;
	int i, min;

	if (ptr == NULL)
	{
		return (malloc(newsize));
		return (tmp);
	}
	else if (newsize == oldsize)
		return (ptr);
	
	else if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		min = (newsize < oldsize) ? newsize : oldsize;
		tmp = malloc(newsize);
		if  (tmp)
		{
			for (i = 0; i < min; i++)
				*((char *)tmp + i) = *((char *)ptr + i);
			free(ptr);
			return (tmp);
		}
		else
			return (NULL);
	}
	
}
