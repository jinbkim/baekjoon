#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int		dp[4][50002];
int		arr[50002];
int		sum[50002];
int		n, m;

void	init(void)
{
	sum[0] = 0;
	memset(dp, 0, sizeof(dp));
}

int		solve(void)
{
	for(int i=1; i<=3; i++)
		for(int j=i*m; j<=n; j++)
			dp[i][j] = max(dp[i][j-1], sum[j]-sum[j-m]+dp[i-1][j-m]);
	return (dp[3][n]);
}


int		main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	init();
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>arr[i];
		sum[i] = sum[i-1]+arr[i];
	}
	cin>>m;
	cout<<solve()<<'\n';
}