#include <stdio.h>
#include <string.h>

int		n;
int		rgb[3];
int		min[3];
int		before[3];

void	init(void)
{
	memset(rgb, 0, sizeof(rgb));
}

int		smaller(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

int		main(void)
{
	int	i;
	init();
	scanf("%d", &n);
	i = -1;
	while (++i < n)
	{
		before[0] = min[0];
		before[1] = min[1];
		before[2] = min[2];
		scanf("%d %d %d", &rgb[0], &rgb[1], &rgb[2]);
		min[0] = smaller(before[1], before[2]) + rgb[0];
		min[1] = smaller(before[0], before[2]) + rgb[1];
		min[2] = smaller(before[0], before[1]) + rgb[2];
	}
	printf("%d\n", smaller(smaller(min[0], min[1]), min[2]));
}