#include <iostream>
#include <cstring>
using namespace std;

bool	visited[502][502];
int		dp[502][502];
int		map[502][502];
int		dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int		n, ret=1;

void	solve(int idx, int y, int x, int before)
{
	int		next_x, next_y;

	// if (idx < dp[y][x])
	// 	return ;
	// dp[y][x] = idx;
	ret = max(ret, idx);
	// cout<<"idx : "<<idx<<", y : "<<y<<",x : "<<x<<",before : "<<before<<", ret : "<<ret<<", dp[y][x] : "<<dp[y][x]<<'\n';

	for(int i=0; i<4; i++)
	{
		next_x = dir[i][0]+x;
		next_y = dir[i][1]+y;
		if (next_x<n && next_y<n && 0<=next_x && 0<=next_y && before < map[next_y][next_x] && !visited[next_y][next_x])
		{
			visited[next_y][next_x] = true;
			solve(idx+1, next_y, next_x, map[next_y][next_x]);
			visited[next_y][next_x] = false;
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	memset(visited, 0, sizeof(visited));
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>map[i][j];
			dp[i][j] = 1;
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			visited[i][j] = true;
			// cout<<"i : "<<i<<", j : "<<j<<'\n';
			solve(1, i, j, map[i][j]);
			visited[i][j] = false;
		}
	
	cout<<ret<<'\n';
}