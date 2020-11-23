#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int		dp[102][100002];
int		w[102], v[102];
int		n, k;

int		solve(int idx, int sum)
{
	int		ret1=0, ret2=0;

	if (dp[idx][sum])
		return (dp[idx][sum]);
	if (idx == n)
		return (0);
	if (w[idx]+sum <= k)
		ret1 = v[idx]+solve(idx+1, w[idx]+sum);
	ret2 = solve(idx+1, sum);
	dp[idx][sum] = max(ret1, ret2);
	return (dp[idx][sum]);
}

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>w[i]>>v[i];
	cout<<solve(0, 0)<<'\n';
}