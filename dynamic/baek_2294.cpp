#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int		dp[10002];
int		arr[102];
int		n, k;

int		main(void)
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	sort(arr+1, arr+n+1);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=k; j++)
			if (0 <= j-arr[i])
				if (dp[j-arr[i]] != -1)
				{
					if (dp[j] == -1)
						dp[j] = dp[j-arr[i]]+1;
					else
						dp[j] = min(dp[j], dp[j-arr[i]]+1);
				}
	cout<<dp[k]<<'\n';
}
