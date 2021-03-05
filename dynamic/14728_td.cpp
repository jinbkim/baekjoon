#include <iostream>
#include <cstring>
using namespace std;

int	dp[102][10002];
int	k[102];
int	s[102];
int	n, t;

int		knapsack(int n, int t)
{
	if (!n || t<=0)
		return(0);
	if (dp[n][t])
		return (dp[n][t]);
	dp[n][t] = knapsack(n-1, t);
	if (0<=t-k[n])
		dp[n][t] = max(dp[n][t], knapsack(n-1, t-k[n])+s[n]);
	return (dp[n][t]);
}

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>t;
	for(int i=1; i<=n; i++)
		cin>>k[i]>>s[i];
	cout<<knapsack(n, t);
}