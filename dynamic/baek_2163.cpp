#include <iostream>
using namespace std;

#define	MAX 302

int		dp[MAX][MAX];
int		n, m;

void	init(void)
{
	int	big = max(n, m);

	for(int i=1; i<=big; i++)
	{
		dp[1][i] = i-1;
		dp[i][1] = i-1;
	}
}

void	solve(void)
{
	for(int i=2; i<=n; i++)
		for(int j=2; j<=m; j++)
		{
			if(j%2)
				dp[i][j] = 1+dp[i][j/2]+dp[i][j/2+1];
			else
				dp[i][j] = 1+dp[i][j/2]*2;
		}
}



int		main(void)
{
	cin>>n>>m;
	init();
	solve();
	cout<<dp[n][m]<<'\n';
}