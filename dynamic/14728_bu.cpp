#include <iostream>
#include <cstring>
using namespace std;

int	dp[102][10002];
int	k[102];
int	s[102];
int	n, t;

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>t;
	for(int i=1; i<=n; i++)
		cin>>k[i]>>s[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=t; j++)
		{
			dp[i][j] = dp[i-1][j];
			if (0 <= j-k[i])
				dp[i][j] = max(dp[i][j], dp[i-1][j-k[i]]+s[i]);
		}
	cout<<dp[n][t];
}