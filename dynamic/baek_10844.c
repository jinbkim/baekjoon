#include <stdio.h>
#include <string.h>

long long	num_arr[10];
long long	dp[101];
int			n;

void	init(void)
{
	int	i;

	dp[1] = 9;
	num_arr[0] = 0;
	i = 0;
	while (++i <= 9)
		num_arr[i] = 1;
}

int		get_dp(void)
{
	long long 	temp[10];
	long long	ret;
	int			i;

	ret = 0;
	temp[0] = num_arr[1];
	temp[9] = num_arr[8];
	i = 0;
	while (++i < 9)
		temp[i] = (num_arr[i - 1] + num_arr[i + 1]) % 1000000000;
	i = -1;
	while (++i <= 9)
	{
		num_arr[i] = temp[i];
		ret = (ret + num_arr[i]) % 1000000000;
	}
	return (ret);
}

void	stair_n(void)
{
	int	i;
	i = 1;
	while(++i <= n)
		dp[i] = get_dp();
}

int		main(void)
{
	scanf("%d", &n);
	init();
	stair_n();
	printf("%lld\n", dp[n]);
}