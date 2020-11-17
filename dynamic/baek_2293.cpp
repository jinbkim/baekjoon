#include <iostream>
#include <cstring>
using namespace std;

int		arr[102];
int		dp[10002];
int		n, k;

int		main(void)
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	dp[0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=k; j++)
			if (0 <= j-arr[i])
				dp[j] += dp[j-arr[i]];
	cout<<dp[k]<<'\n';
}
