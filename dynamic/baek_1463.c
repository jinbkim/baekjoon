#include <stdio.h>
#include <string.h>

int		dp[1000000];

void	init(void)
{
	memset(dp, -1, sizeof(dp));
}

void	make_one(int n, int idx)
{
	if (n < 1 || (dp[n] < idx && dp[n] != -1))
		return ;
	dp[n] = idx;
	if (!(n % 3))
		make_one(n / 3, idx + 1);
	if (!(n % 2))
		make_one(n / 2, idx + 1);
	make_one(n - 1, idx + 1);
}

int		main(void)
{
	int n;

	scanf("%d", &n);
	init();
	make_one(n, 0);
	printf("%d\n", dp[1]);
}