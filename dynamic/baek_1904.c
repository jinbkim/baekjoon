#include <stdio.h>
#include <string.h>

int		arr[1000001];
int		n;

void		init(void)
{
	memset(arr, -1, sizeof(arr));
	arr[1] = 1;
	arr[2] = 2;
}

int			main(void)
{
	int		i;

	scanf("%d", &n);
	init();
	i = 2;
	while (++i <= n)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 15746;
	}
	printf("%d\n", arr[n]);
}