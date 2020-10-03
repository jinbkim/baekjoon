#include <stdio.h>
#include <string.h>

int		arr[1000];
int		flag[1000][2];
int		n;

void	init(void)
{
	memset(flag, 0, sizeof(flag));
	flag[0][0] = 1;
}

int		bigger(int n1, int n2)
{
	if (n1 <= n2)
		return (n2);
	else
		return (n1);
}

int		find_val(int idx)
{
	int	i, max, max_i;

	max = 0;
	max_i = -1;
	i = -1;
	while (++i < idx)
	{
		if (max < flag[i][0] && arr[i] < arr[idx])
		{
			max = flag[i][0];
			max_i = i;
		}
	}
	if (max_i == -1)
		return  (1);
	else
		return (flag[max_i][0] + 1);
}

void	get_seq(void)
{
	int	i;

	i = 0;
	while (++i < n)
	{
		flag[i][0] = find_val(i);
		flag[i][1] = bigger(flag[i - 1][0], flag[i - 1][1]);
	}
}

int		main(void)
{
	int	i;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
		scanf("%d", &arr[i]);
	init();
	get_seq();
	printf("%d\n", bigger(flag[n - 1][0], flag[n - 1][1]));
}