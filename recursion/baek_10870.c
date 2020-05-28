#include <stdio.h>

int		fibonacci(int num)
{
	if (num == 0)
		return (0);
	else if (num == 1)
		return (1);
	else
		return (fibonacci(num - 1) + fibonacci(num - 2));  // F(n) = F(n-1) + F(n-2)
}

int		main(void)
{
	int	num;
	
	scanf("%d", &num);
	getchar();
	printf("%d\n", fibonacci(num));
}
