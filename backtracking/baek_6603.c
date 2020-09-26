#include <stdio.h>
#include <string.h>

int		check_ascending(int *bucket)
{
	int i;

	i = -1;
	while (++i < 5)
		if (bucket[i + 1] < bucket[i])
			return (0);
	return (1);
}

void	lotto(int *bucket, int *flag, int *arr, int n, int idx)
{
	int	i;

	if (idx == 6)
	{
		if (!check_ascending(bucket))
			return ;
		i = -1;
		while (++i < 6)
			printf("%d ", bucket[i]);
		printf("\n");
		return ;
	}
	i = -1;
	while (++i < n)
	{
		if (flag[i])
			continue;
		flag[i] = 1;
		bucket[idx] = arr[i];
		lotto(bucket, flag, arr, n, idx + 1);
		flag[i] = 0;
	}
}

int		main(void)
{
	int	bucket[15];
	int	flag[15];
	int	arr[15];
	int	n, i;

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break ;
		i = -1;
		memset(bucket, 0, sizeof(bucket));
		memset(flag, 0, sizeof(flag));
		memset(arr, 0, sizeof(arr));
		while (++i < n)
			scanf("%d", &arr[i]);
		lotto(bucket, flag, arr, n, 0);
		printf("\n");
	}
}