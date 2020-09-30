#include <stdio.h>

int		stairs[301];
int		dp[301];
int		n;

int		bigger(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	else
		return (n2);
}

void	init(void)
{
	dp[0] = stairs[0];
	dp[1] = stairs[0] + stairs[1];
	dp[2] = bigger(stairs[0] + stairs[2], stairs[1] + stairs[2]);
}

void	climbing_stairs(void)
{
	int		i;

	i = 2;
	while (++i < n)
		dp[i] = bigger(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
}

int		main(void)
{
	int		i;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
		scanf("%d", &stairs[i]);
	init();
	climbing_stairs();
	printf("%d\n", dp[n - 1]);
}