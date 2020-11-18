#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long	dp[102];
int		n;

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n;
	for(int i=1; i<=6; i++)
		dp[i] = i;
	for(int i=7; i<=n; i++)
		for(int j=i-3; 0<=j; j--)
			dp[i] = max(dp[i], dp[j]*(i-j-1));
	cout<<dp[n]<<'\n';
}