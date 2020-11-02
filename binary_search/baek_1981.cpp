#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX	202

bool	visited[MAX][MAX];
int		map[MAX][MAX];
int		dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
int		n, map_max=0, map_min=MAX;

void	dfs(int y, int x)
{
	int		next_x, next_y;

	if (visited[y][x])
		return ;
	visited[y][x] = true;
	for(int i=0; i<4; i++)
	{
		next_x = x+dir[i][0];
		next_y = y+dir[i][1];
		if (1<=next_x && next_x<=n && 1<=next_y && next_y<=n)
			dfs(next_y, next_x);
	}
}

bool	is_possible (int val)
{
	for(int i=map_min; i<=map_max; i++)
	{
		if (map[1][1]<i ||  i+val<map[1][1] || map[n][n]<i || i+val<map[n][n])
			continue ;
		memset(visited, true, sizeof(visited));	
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if (i<=map[j][k] && map[j][k]<=i+val)
					visited[j][k] = false;
		dfs(1, 1);
		if (visited[n][n])
			return (true);
	}
	return (false);
}

int		bs(int left, int right)
{
	int		mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	return (ans);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			cin>>map[i][j];
			map_max = max(map_max, map[i][j]);
			map_min = min(map_min, map[i][j]);
		}
	cout<<bs(0, map_max)<<'\n';
}