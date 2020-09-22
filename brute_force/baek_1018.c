#include <stdio.h>

#define	MAX	9999

int		chess_paint(int n, int m, char str[][51])
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	val[2];
	int	ret;

	i = -1;
	ret = MAX;
	while (++i < n - 7)
	{
		j = -1;
		while (++j < m - 7)
		{
			k = -1;
			val[0] = 0;
			val[1] = 0;
			while (++k < 8)
			{
				l = -1;
				while (++l < 8)
				{
					if (((k + l) % 2 && str[i + k][j + l] == 'W') || (k + l) % 2 == 0 && str[i + k][j + l] == 'B')
						val[0]++;
					if (((k + l) % 2 && str[i + k][j + l] == 'B') || (k + l) % 2 == 0 && str[i + k][j + l] == 'W')
						val[1]++;
				}
			}
			if (val[0] < ret)
				ret = val[0];
			if (val[1] < ret)
				ret = val[1];
		}
	}
	return (ret);
}

int		main(void)
{
	char	str[51][51];
	int		n;
	int		m;
	int		i;

	scanf("%d %d", &n, &m);
	i = -1;
	while (++i < n)
		scanf("%s",str[i]);
	printf("%d\n", chess_paint(n, m, str));
}