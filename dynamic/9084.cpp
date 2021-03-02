#include <iostream>
#include <cstring>
using namespace std;

int	dp[10002];
int	arr[22];
int	t, n, m;

int		main(void)
{
	cin>>t;
	for(int i=0; i<t; i++)
	{
		memset(dp, 0, sizeof(dp));
		cin>>n;
		for(int j=1; j<=n; j++)
			cin>>arr[j];
		cin>>m;
		dp[0] = 1;
		for(int j=1; j<=n; j++)
			for(int k=1; k<=m; k++)
				if (arr[j] <= k)
					dp[k] += dp[k-arr[j]];
		cout<<dp[m]<<'\n';
	}
}