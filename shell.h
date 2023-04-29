#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>

int _putchar(char c);
char **_strtok(char *command, size_t *count);
void handleCommand(char *cmd);
void runprog(char *path, char **args);
int _strcmp(char *str1, char *str2);

#endif
