#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#define READ_BUF 1024

void ctrl_C(int);
int _strlen(char *s);
char *_getline(void);
int print(char *var, int fd);
void *_realloc(void *ptr, int oldsize, int newsize);
#endif
