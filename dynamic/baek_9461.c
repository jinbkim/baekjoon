#include <stdio.h>

long long	arr[101];
int			n;

void	init(void)
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
}

int		main(void)
{
	int	i, j, k;

	scanf("%d", &n);
	i = -1;
	init();
	while (++i < n)
	{
		scanf("%d", &k);
		j = 5;
		while (++j <= k)
			arr[j] = arr[j - 1] + arr[j - 5];
		printf("%lld\n", arr[k]);
	}
}