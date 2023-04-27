#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int handleCommand(char *cmd);
char **_strtok(char *command, size_t *count);
int runprog(char *path);

#endif
