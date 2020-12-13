#include <iostream>
#include <cstring>
using namespace std;

char	map[102][102];
int		dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int		dp[102][102];
int		m, n;

void	init(void)
{
	memset(dp, -1, sizeof(dp));
}

void	dfs(int y, int x, int c)
{
	int		next_y, next_x;

	if (dp[y][x] != -1 && dp[y][x] <= c)
		return ;
	// cout<<"y : "<<y<<", x : "<<x<<", c : "<<c<<'\n';
	dp[y][x] = c;	
	for(int i=0; i<4; i++)
	{
		next_x = dir[i][0]+x;
		next_y = dir[i][1]+y;
		if (1<=next_x && next_x<=m && 1<=next_y && next_y<=n)
		{
			if (map[next_y][next_x] == '0')
				dfs(next_y, next_x, c);
			else if (map[next_y][next_x]=='1' && (dir[i][0]==1||dir[i][1]==1))
				dfs(next_y, next_x, c+1);
		}
	}
}


int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>m>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map[i][j];
	init();
	dfs(1, 1, 0);
	cout<<dp[n][m]<<'\n';
}