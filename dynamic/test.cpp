#include <iostream>
#include <cstring>
using namespace std;

int		dp[502][502];
int		map[502][502];
int		dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int		n, ret=1;

void	init(void)
{
	memset(dp, 0, sizeof(dp));
}

int		solve(int idx, int y, int x, int before_y, int before_x)
{
	int		next_x, next_y;

	if (dp[before_y][before_x])
	{
		dp[y][x] = dp[before_y][before_x]+1;
		return (dp[y][x]);
	}

	for(int i=0; i<4; i++)
	{
		next_x = dir[i][0]+x;
		next_y = dir[i][1]+y;
		if (next_x<n && next_y<n && 0<=next_x && 0<=next_y && map[before_y][before_x] < map[next_y][next_x])
		{
			dp[next_y][next_x] = solve(idx+1, next_x, next_y, y, x);
		}
	}
	return (dp[y][x]);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	init();
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>map[i][j];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			ret = max(ret, solve(1, i, j, i, j));
	cout<<ret<<'\n';
}