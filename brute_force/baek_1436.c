#include <stdio.h>

int		arr[10001];

int		check666(int n)
{
	int	consec_six;

	consec_six = 0;
	while (n > 0)
	{
		if (n % 1000 == 666)
			return (1);
		n /= 10;
	}
	return (0);
}

void	find666(int n)
{
	int	i,j;

	i = 0;
	j = 665;
	while (++j && i != n)
		if (check666(j))
			arr[++i] = j;
}

int		main(void)
{
	int	n;

	scanf("%d", &n);
	find666(n);
	printf("%d\n", arr[n]);
}