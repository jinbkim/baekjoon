#include <iostream>
#include <cstring>

using namespace std;

int		map[51][51];
int		visted[51][51];
int		dir[8][2] = {{-1,-1}, {-1,0}, {-1, 1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1, 1}};
int		w, h, ret;

void	init(void)
{
	memset(visted, 0, sizeof(visted));
	ret = 0;
}

bool	is_inside(int y, int x)
{
	if (0 <= x && x <= w-1 && 0 <= y && y <= h-1)
		return (true);
	else
		return (false);
}

int		dfs(int y, int x)
{
	int	next_x, next_y;

	if (visted[y][x] || !map[y][x])
		return (false);
	else
	{
		visted[y][x] = true;
		for(int i=0; i<8; i++)
		{
			next_x = x+dir[i][0];
			next_y = y+dir[i][1];
			if (is_inside(next_y, next_x) && map[next_y][next_x] && !visted[next_y][next_x])
				dfs(next_y, next_x);
		}
		return (true);
	}
}



int		main(void)
{
	while (1)
	{
		init();
		cin>>w>>h;
		if (!w && !h)
			break ;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				cin>>map[i][j];
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				if (dfs(i, j))
					ret++;
		cout<<ret<<'\n';	
	}
}