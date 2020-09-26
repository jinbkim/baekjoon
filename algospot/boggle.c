#include <stdio.h>
#include <string.h>

char	str[6][6];
char	ans[11];
int		dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int		dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int		visit[6][6];
int		n, m, find;


void	boggle(int y, int x, int idx)
{
	int	i;
	if (!ans[idx + 1])
	{
		if (ans[idx] == str[y][x])
			find = 1;
		return ;
	}
	i = -1;
	while (++i < 8)
	{
		if (!(0 <= x + dx[i] && x + dx[i] <= 4 && 0 <= y + dy[i] && y + dy[i] <= 4))
			continue ;
		if (str[y][x] == ans[idx])
			boggle(y + dy[i], x + dx[i], idx + 1);
		if (find)
			return ;
	}
}

int		main(void)
{
	int		i, j, k, l;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
	{
		memset(str, 0, sizeof(str));
		memset(ans, 0, sizeof(ans));
		memset(visit, 0, sizeof(visit));
		j = -1;
		while (++j < 5)
			scanf("%s", str[j]);
		scanf("%d", &m);
		j = -1;
		while (++j < m)
		{
			find = 0;
			scanf("%s", ans);
			k = -1;
			while (++k < 5)
			{
				l = -1;
				while (++l < 5)
					boggle(l, k, 0);
				if (find)
					break ;
			}
			if (find)
				printf("%s YES\n", ans);
			else
				printf("%s NO\n", ans);
		}
	}
}