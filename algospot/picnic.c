#include <stdio.h>
#include <string.h>

int		freinds[50][2];
int		visit[10];
int		c, n, m, result;

void	init(void)
{
	memset(freinds, 0 , sizeof(freinds));
	memset(visit, 0, sizeof(visit));
	result = 0;
}

void	picnic(int idx1, int idx2)
{
	int	i;

	if (n / 2 == idx2)
	{
		i = -1;
		while (++i < n)
			if (visit[i] == 0)
				return ;
		result++;
		return ;
	}
	i = idx1 - 1;
	while (++i < m)
	{
		if (visit[freinds[i][0]] || visit[freinds[i][1]])
			continue ;
		visit[freinds[i][0]] = 1;
		visit[freinds[i][1]] = 1;
		picnic(i + 1, idx2 + 1);
		visit[freinds[i][0]] = 0;
		visit[freinds[i][1]] = 0;
	}
}


int		main(void)
{
	int	i, j, temp;

	scanf("%d", &c);
	i = -1;
	while (++i < c)
	{
		init();
		scanf("%d %d", &n, &m);
		j = -1;
		while (++j < m)
			scanf("%d %d", &freinds[j][0], &freinds[j][1]);
		picnic(0, 0);
		printf("%d\n", result);
	}
}