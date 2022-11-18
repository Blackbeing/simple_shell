#include "shell.h"

/**
 * _strtok - parse arguments
 *@string: str argument
 *
 * Return: list of arguments
 */

char **_strtok(char *string)
{
	int BUF = 1024, pos = 0;
	char **toks = malloc(sizeof(char) * BUF);
	char *delim = " ";
	char *tok;

	if (!toks)
		exit(EXIT_FAILURE);

	tok = strtok(string, delim);
	while (tok != NULL)
	{
		toks[pos] = tok;
		tok = strtok(NULL, delim);
		pos++;
	}
	toks[pos] = NULL;
	return (toks);
}
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
	int status;
	char *buffer;
	char **toks;
	pid_t child_pid;

	while (1)
	{
		/* Print prompt if only is tty */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 3);
		buffer = _read_buffer();
		toks = _strtok(buffer);

		child_pid = fork();

		if (child_pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			status = execve(toks[0], toks, env);
			if (status == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", toks[0], toks[2]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{

			waitpid(child_pid, &status, 0);
		}
	}

		/* check if running from child process */
	free(toks);
	free(buffer);
	return (0);
}
