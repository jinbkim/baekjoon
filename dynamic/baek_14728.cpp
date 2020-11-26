#include <iostream>
#include <cstring>
using namespace std;

int		dp[102][10002];
int		k[102], s[102];
int		n, t, ret=0;

int		solve(int idx, int time)
{
	int		ret1=0, ret2=0;

	if (dp[idx][time])
		return (dp[idx][time]);
	if (idx == n)
		return (0);
	if (time+k[idx] <= t)
		ret1 = solve(idx+1, time+k[idx])+s[idx];
	ret2 = solve(idx+1, time);
	dp[idx][time] = max(ret1, ret2);
	return (dp[idx][time]);
}

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>t;
	for(int i=0; i<n; i++)
		cin>>k[i]>>s[i];
	cout<<solve(0, 0)<<'\n';
}