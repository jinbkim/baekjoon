#include <stdio.h>
#include <string.h>

char	flag[10];
int		arr[9];

void	find_sequence(int n, int m, int idx)
{
	int	i;

	i = -1;
	if (idx == m)
	{
		while (++i < m)
			printf("%d ", arr[i]);
		printf("\n");
		return ;
	}
	i = 0;
	while (++i <= n)
	{
		if (!flag[i])
		{
			arr[idx] = i;
			flag[i] = 1;
			find_sequence(n, m, idx + 1);
			flag[i] = 0;
		}
	}
}

int		main(void)
{
	int		n;
	int		m;

	scanf("%d %d", &n, &m);
	memset(arr, 0, sizeof(arr));
	memset(flag, 0, sizeof(flag));
	find_sequence(n, m, 0);
}