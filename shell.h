#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int _strlen(char *s);
int space_checker(int i, char *s);
char **strtoking(char *s);
int process(char **cmd);

#endif /*#ifndef _SHELL_H_*/
