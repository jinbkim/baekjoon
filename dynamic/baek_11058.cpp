#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long	dp[102];
int		n;

int		main(void)
{
	cin>>n;
	for(int i=1; i<=6; i++)
		dp[i] = i;
	for(int i=7; i<=n; i++)
		dp[i] = max(dp[i-3]*2, dp[i-4] * 3);
	cout<<dp[n]<<'\n';
}