#include <stdio.h>
#include <string.h>

char	map[21][21];
int		visit[21][21];
int		block_x[4][3] = {{1, 0, 1}, {0, 0, 1}, {0, 1, 1}, {0, 1, 0}};
int		block_y[4][3] = {{0, 1, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0, 1}};
int		flag;
int		c, h, w, empty, ret;

void	init(void)
{
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	flag = 0;
}

void	cover(int y, int x, int idx)
{
	int	i, j, k, l;

	if (idx == empty / 3)
	{
		ret++;
		return ;
	}
	i = y - 1;
	while (++i < h - 1)
	{
		if (!flag)
		{
			j = x - 1;
			flag = 1;
		}
		else
			j = -1;
		while (++j < w - 1)
		{
			k = -1;
			while (++k < 4)
			{
				if ((visit[i + block_y[k][0]][j + block_x[k][0]] || visit[i + block_y[k][1]][j + block_x[k][1]] || visit[i + block_y[k][2]][j + block_x[k][2]]))
					continue ;
				visit[i + block_y[k][0]][j + block_x[k][0]] = 1;
				visit[i + block_y[k][1]][j + block_x[k][1]] = 1;
				visit[i + block_y[k][2]][j + block_x[k][2]] = 1;
				if (j == w - 2)
					cover(i + 1, 0, idx + 1);
				else
				{
					flag = 0;
					cover(i , j + 1, idx + 1);
				}
				visit[i + block_y[k][0]][j + block_x[k][0]] = 0;
				visit[i + block_y[k][1]][j + block_x[k][1]] = 0;
				visit[i + block_y[k][2]][j + block_x[k][2]] = 0;
			}
		}
	}
}

int		count_empty(void)
{
	int	i, j, ret;

	ret = 0;
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			if (map[i][j] == '.')
				ret++;
			else
				visit[i][j] = 1;
		}
	}
	return (ret);
}

int		main(void)
{
	int	i, j;

	scanf("%d", &c);
	i = -1;
	while (++i < c)
	{
		init();
		scanf("%d %d", &h, &w);
		j = -1;
		while (++j < h)
			scanf("%s", map[j]);
		empty = count_empty();
		if (empty % 3)
			printf("0\n");
		else
		{
			cover(0, 0, 0);
			printf("%d\n", ret);
		}
	}
}