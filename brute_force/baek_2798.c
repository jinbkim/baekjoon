#include <stdio.h>

int		new_blackjack(int n, int m, int *nums)
{
	int	ret;
	int	i;
	int	j;
	int	k;

	ret = 0;
	i = -1;
	while (++i < n - 2)
	{
		j = i;
		while (++j < n - 1)
		{
			k = j;
			while (++k < n)
				if (nums[i] + nums[j] + nums[k] <= m)
					if (ret < nums[i] + nums[j] + nums[k])
						ret = nums[i] + nums[j] + nums[k];
		}
	}
	return (ret);
}

int		main(void)
{
	int	nums[100];
	int	n;
	int	m;
	int	i;

	scanf("%d %d", &n, &m);
	i = -1;
	while (++i < n)
		scanf("%d", &nums[i]);
	printf("%d\n", new_blackjack(n, m , nums));
}