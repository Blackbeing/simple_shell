#include "shell.h"

/**
 * main - main loop for shell program
 * @argc: number of arguments
 * @argv: arguments
 * @env: environment variables
 *
 * Return: (0) Success;
 */

int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)),
		char *env[] __attribute__((unused)))
{
	char *buffer;
	int nread = 0, status;
	int mode = isatty(STDIN_FILENO);
	size_t n;
	pid_t child_pid;

	if (!mode)
	{
		nread = getline(&buffer, &n, stdin);
		buffer[nread - 1] = '\0';
		if (execve(buffer, argv, env) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}

	}
	else
	{
		while (mode)
		{
			mode = isatty(STDIN_FILENO);
			if (mode == 1)
			{
				write(STDOUT_FILENO, "#cisfun$ ", 10);
				child_pid = fork();

				if (child_pid == 0)
				{

					nread = getline(&buffer, &n, stdin);
					if (nread == -1)
					{
						write(STDOUT_FILENO, "\n", 2);
						exit(EXIT_FAILURE);

					}
					buffer[nread - 1] = '\0';
					if (execve(buffer, argv, NULL) == -1)
					{
						fprintf(stderr, "%s: No such file or directory\n", argv[0]);
						exit(EXIT_FAILURE);
					}
				}
				else
					waitpid(child_pid, &status, 0);
			}
		}
	}
	return (0);
}
