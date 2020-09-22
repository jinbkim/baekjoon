#include <stdio.h>
#include <string.h>

char	flag[10];
int		input[10];
int		arr[10];

void	sort_input(int *input, int n)
{
	int i;
	int	j;
	int	temp;

	i = -1;
	while (++i < n - 1)
	{
		if (input[i + 1] < input[i])
		{
			temp = input[i];
			input[i] = input[i + 1];
			input[i + 1] = temp;
			i = -1;
		}
	}
}

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
			arr[idx] = input[i - 1];
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
	int		i;

	memset(arr, 0, sizeof(arr));
	memset(flag, 0, sizeof(flag));
	memset(input, 0, sizeof(input));

	scanf("%d %d", &n, &m);
	i = -1;
	while (++i < n)
		scanf("%d", &input[i]);
	sort_input(input, n);
	find_sequence(n, m, 0);
}