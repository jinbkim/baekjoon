#include <iostream>
#include <cstring>
using namespace std;

bool	dp[32][30000];
int		w1[32], w2[9];
int		n, m;

void	init(void)
{
	memset(dp, false, sizeof(dp));
}

void	solve(int idx, int sum)
{
	if (dp[idx][sum])
		return ;
	if (idx == n)
	{
		if (sum >= 0)
			dp[idx][sum] = true;
		return ;
	}
	dp[idx][sum] = true;
	solve(idx+1, sum+w1[idx]);
	solve(idx+1, sum-w1[idx]);
	solve(idx+1, sum);
}



int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>w1[i];
	cin>>m;
	for(int i=0; i<m; i++)
		cin>>w2[i];
	init();
	solve(0, 15000);
	for(int i=0; i<m; i++)
	{
		if (dp[n][w2[i]+15000])
			cout<<'Y'<<' ';
		else
			cout<<'N'<<' ';
	}
}