#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - unix command line with arguments  interpreter 
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	pid_t pid;
char input[1024];
while (1)
{
printf("simple_shell> ");
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';
if (input[0] == '\0')
{
continue;
}
if (access(input, X_OK) != 0)
{
fprintf(stderr, "Command not found: %s\n", input);
continue;
}
pid = fork();
if (pid == 0)
{
char *args[64];
char *token = strtok(input, " ");
int i = 0;
while (token != NULL)
{
args[i] = token;
token = strtok(NULL, " ");
i++;
}
args[i] = NULL;
if (execvp(args[0], args) == -1)
{
perror("Command execution error");
exit(1);
}
}
else if (pid < 0)
{
perror("Fork error");
}
else
{
int status;
wait(&status);
}
}
return (0);
}
