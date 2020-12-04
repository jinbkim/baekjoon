#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int		dp[17];
int		t[17], p[17];
int		n;

void	solve(void)
{
	for(int i=1; i<=n+1; i++)
		for(int j=1; j<i; j++)
			if (t[j] <= i-j)
				dp[i] = max(dp[i], dp[j]+p[j]);
}

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>t[i]>>p[i];
	solve();
	cout<<dp[n+1]<<'\n';
}