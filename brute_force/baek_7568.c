#include <stdio.h>

void	show_order(int arr[][2], int n)
{
	int	order_arr[50];
	int	order;
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		order = 1;
		while (++j < n)
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				order++;
		order_arr[i] = order;
	}
	i = -1;
	while (++i < n)
		printf("%d ", order_arr[i]);
	printf("\n");
}

int		main(void)
{
	int	arr[50][2];
	int	n;
	int	i;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	show_order(arr, n);
}