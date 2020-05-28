#include <stdio.h>

int		factorial(int num)
{
	if (num == 0)
		return (1);
	else if (num == 1)
		return (1);
	else
		return (num * factorial(num - 1));  // n! = n * (n-1)!
}

int		main(void)
{
	int	num;
	
	scanf("%d", &num);
	getchar();
	printf("%d\n", factorial(num));
}
