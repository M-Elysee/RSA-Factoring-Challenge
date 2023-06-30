#include <stdio.h>
#include <stdlib.h>
int factor(long long number);
/**
* main - is the main function of our program
* @argc: is the number of arguments in the commandline
* @argv: points to the array of pointers to the commandline arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *fl;
	char *ptr;
	size_t size;
	long long number;
	ssize_t line;

	if (argc != 2)
	{
		fprintf(stdout, "Usage: factor <file>\n");
		exit(EXIT_FAILURE);
	}
	fl = fopen(argv[1], "r");
	if (!fl)
	{
		fprintf(stdout, "Error: can't open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do {
		ptr = NULL;
		line = getline(&ptr, &size, fl);
		if (line > 0)
		{
			number = atoll(ptr);
			factor(number);
		}
		free(ptr);
	} while (line > 0);
	fclose(fl);
	return 0;
}
/**
* factor - rints the factors of a number passed into as arguments
* @number: is the number to be factorized
* Return: 0 on success
*/
int factor(long long number)
{
	long long i, num;

	for (i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			num = number / i;
			printf("%lld=%lld*%lld\n", number, num, i);
			return (0);
		}
	}
	printf("it is a prime number");
	return (0);
}
