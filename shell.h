#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *_read_buffer(void);
char **_strtok(char *string);


#endif /* SHELL_H */
