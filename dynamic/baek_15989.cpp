#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int		dp[10002][4];
int		n, m, ret, m_max=3;

void	init(void)
{
	memset(dp, 0, sizeof(dp));
	dp[2][2] = 1;
}

void	solve(void)
{
	for(int i=m_max; i<=m; i++)
	{
		dp[i][2] = 1+dp[i-2][2];
		dp[i][3] = 1+dp[i-3][2]+dp[i-3][3];
	}
}



int		main(void)
{
	init();
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>m;
		solve();
		m_max = max(m, m_max);
		cout<<1+dp[m][2]+dp[m][3]<<'\n';
	}
}