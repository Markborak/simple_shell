#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - unix command line interpreter
 *
 * Return: Always 0 (success)
 *
 */

int main(void)
{
pid_t pid;

char input[1024];

while (1)
{
printf("simple_shell>");
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}

input[strcspn(input, "\n")] = '\0';

if (input[0] == '\0')
{
continue;
}

pid = fork();
if (pid == 0)
{
if (execl(input, input, (char *)NULL) == -1)
{
perror("Command execution error");
exit(1);
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

}
return (0);
}
