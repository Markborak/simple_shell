#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - simple unix command line interpreter
 *
 * execute_command - launches new child process to execute user command
 *
 *@command: parameter
 *
 * Return: Always 0 (success)
 *
 */

void execute_command(const char *command)
{
pid_t pid = fork();
if (pid == 0)
{
if (execl(command, command, (char *)NULL) == -1)
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

int main(void)
{
char input[1024];
while (1)
{
printf("simple_shell>");
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';
if (input[0] != '\0')
{
execute_command(input);
}
}
return (0);
}
