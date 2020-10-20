#include <iostream>
#include <cstring>

using namespace std;

int		map1[102][102];
int		map2[102][102];
int		map3[102][102];
int		dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0,1}};
int		n, ret, ret_max, max_n;

void	init1(void)
{
	max_n = 0;
	ret_max = 0;
	memset(map2, 0, sizeof(map2));
}

void	init2(void)
{
	ret = 0;
	memset(map3, 0, sizeof(map3));
}

bool	is_inside(int y, int x)
{
	if (0 <= x && x <= n-1 && 0 <= y && y <= n-1)
		return (true);
	else
		return (false);
}

bool	dfs(int y, int x)
{
	int	next_x, next_y;

	if (map3[y][x] || map2[y][x])
		return (false);
	map3[y][x] = true;
	for(int i=0; i<4; i++)
	{
		next_x = x+dir[i][0];
		next_y = y+dir[i][1];
		if (is_inside(next_y, next_x) && !map2[next_y][next_x] && !map3[next_y][next_x])
			dfs(next_y, next_x);
	}
	return (true);
}

int		main(void)
{
	init1();
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>map1[i][j];
			if (max_n < map1[i][j])
				max_n = map1[i][j];
		}
	for(int i=0; i<=max_n; i++)
	{
		init2();
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if (map1[j][k] == i)
					map2[j][k] = 1;
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if (dfs(j, k))
					ret++;
		if (ret_max < ret)
			ret_max = ret;
	}
	cout<<ret_max<<'\n';
}