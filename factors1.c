#include <stdio.h>
#include <stdlib.h>
int factor(long long number);
int prime(long long n);
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
	long long number;
	ssize_t line;
	size_t size = 0;

	if (argc != 2)
	{
		fprintf(stdout, "Usage: factors <file>");
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
	return (0);
}
/**
* factor - finds two prime factors of a number
* @number: is the number to factorize
* Return: 0 on success
*/
int factor(long long number)
{
	long long i, j, k = -1;
	long long *num;

	for (i = 2; i < number; i++)
	{
		if (number % i == 0 && prime(i))
		{
			num[++k] = i;
			j = number / i;
			if (prime(j))
				num[++k] = j;
		}
		if (k > 0)
		{
			printf("%lld=%lld*%lld\n", number, num[1], num[0]);
			return (0);
		}
	}
	printf("Error not RSA Number");
	return (0);
}
/**
* prime - tests if a number is prime
* @n: is the number to be tested
* Return: 1 if prime  and 0 if not
*/
int prime(long long n)
{
	long long i;

	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}
