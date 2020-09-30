#include <stdio.h>
#include <string.h>

int		nums[501];
int		max[501];
int		before[501];
int		n;

void	init(void)
{
	memset(max, 0, sizeof(max));
}

int		bigger(int n1, int n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

int		find_max(int *max)
{
	int i, ret;

	ret = max[0];
	i = 0;
	while (++i < n)
		if (ret < max[i])
			ret = max[i];
	return (ret);
}

int		main(void)
{
	int	i, j;

	scanf("%d", &n);
	init();
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j <= i)
		{
			before[j] = max[j];
			scanf("%d", &nums[j]);
			if (j == 0)
				max[j] = before[j] + nums[j];
			else if (j == i)
				max[j] = before[j - 1] + nums[j];
			else
				max[j] = bigger(before[j - 1], before[j]) + nums[j];
		}
	}
	printf("%d\n", find_max(max));
}