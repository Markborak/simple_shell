#include <stdio.h>

/**
*main - code that finds the average of two numbers
*
*Return: Always 0 (success)
*/

int main(void)
{
int i, j;
float average;
printf("enter your first no:\n");
scanf("%d", &i);
printf("enter your second no;\n");
scanf("%d", &j);

average = (i + j) / 2;
printf("%f\n", average);

return (0);
}
