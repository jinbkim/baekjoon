#include <stdio.h>
#include <string.h>

int		arr[10];
int		max, ret, n , k;

void	init()
{
	memset(arr, 0, sizeof(arr));
	max = 0;
	ret = 0;
}

void	get_val(int num)
{
	int	temp;

	temp = ret;
	ret *= 10;
	ret += num;
	if (n < ret)
		ret = temp;
}

void	recur(int idx)
{
	int	i;
	int	temp;
	if (k == idx)
	{
		if (max < ret && ret <= n)
			max = ret;
		return ;
	}
	i = -1;
	while (++i < k)
	{
		temp = ret;
		get_val(arr[i]);
		recur(idx + 1);
		ret = temp;
	}
}



int		main(void)
{
	int	i;

	scanf("%d %d", &n, &k);
	init();
	i = -1;
	while (++i < k)
		scanf("%d", &arr[i]);
	recur(0);
	printf("%d\n", max);
}