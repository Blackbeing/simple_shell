#include "shell.h"

int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)),
		char *env[] __attribute__((unused)))
{
	char *buffer;
	int nread = 0;
	size_t n;

	while (1)
	{
		printf("$ ");

		if ((nread = getline(&buffer, &n, stdin)) == -1)
		{
			perror("Getline");
			exit(EXIT_FAILURE);
		}
		buffer[nread-1] = '\0';
		execve(buffer, argv, env);
	}
	return (0);
}
