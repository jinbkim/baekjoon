#include <iostream>
#include <cstring>
using namespace std;

#define	MAX	1002

int		dp[MAX][MAX];
int		map[MAX][MAX];
int		n, m;

void	init(void)
{
	memset(dp, 0, sizeof(dp));
}

void	solve(void)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			map[i][j] += max(map[i][j-1], map[i-1][j]);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	init();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map[i][j];
	solve();
	cout<<map[n][m]<<'\n';
}