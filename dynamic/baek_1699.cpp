#include <iostream>
#include <algorithm>

using namespace std;

int		main(void)
{
	int		arr[100001];
	int		dp[100001];
	int		n;

	cin>>n;
	for(int i=0; i<=n; i++)
	{
		dp[i] = i;
		for(int j=1; j*j<=i; j++)
			dp[i] = min(dp[i], dp[i-j*j]+1);
	}
	cout<<dp[n]<<'\n';
}