#include <stdio.h>
#include <string.h>

int		arr[10];

int		check_ascending(int *arr, int m)
{
	int	i;

	i = -1;
	while (++i < m - 1)
		if (arr[i + 1] < arr[i])
			return (0);
	return (1);
}

void	find_sequence(int n, int m, int idx)
{
	int	i;

	i = -1;
	if (idx == m)
	{
		if (!check_ascending(arr, m))
			return ;
		while (++i < m)
			printf("%d ", arr[i]);
		printf("\n");
		return ;
	}
	i = 0;
	while (++i <= n)
	{
		arr[idx] = i;
		find_sequence(n, m, idx + 1);
	}
}

int		main(void)
{
	int		n;
	int		m;

	scanf("%d %d", &n, &m);
	memset(arr, 0, sizeof(arr));
	find_sequence(n, m, 0);
}