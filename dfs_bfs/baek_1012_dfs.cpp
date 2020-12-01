#include <iostream>
#include <cstring>
using namespace std;

bool	map[52][52];
int		dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int		t, m, n, k, x, y, ret=0;

void	init(void)
{
	memset(map, 0, sizeof(map));
	ret = 0;
}

bool	dfs(int x, int y)
{
	int		next_x, next_y;

	if (!map[x][y])
		return (false);
	map[x][y] = false;
	for(int i=0; i<4; i++)
	{
		next_x = x+dir[i][0];
		next_y = y+dir[i][1];
		if (0<=next_x && next_x<m && 0<=next_y && next_y<n)
			dfs(next_x, next_y);
	}
	return (true);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>t;
	for(int i=0; i<t; i++)
	{
		init();
		cin>>m>>n>>k;
		for(int j=0; j<k; j++)
		{
			cin>>x>>y;
			map[x][y] = true;
		}
		for(int j=0; j<m; j++)
			for(int h=0; h<n; h++)
				if (dfs(j, h))
					ret++;
		cout<<ret<<'\n';
	}
}