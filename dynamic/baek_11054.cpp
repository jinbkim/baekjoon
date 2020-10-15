#include <iostream>

using namespace std;

int		main(void)
{
	int		dp[1001][2];
	int		arr[1001];
	int		n, dp_max, ret;

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	dp[0][0] = 1;	
	for(int i=1; i<n; i++)
	{
		dp_max = 0;
		for(int j=0; j<i; j++)
		{
			if (arr[j] < arr[i] && dp_max < dp[j][0])
				dp_max = dp[j][0];
		}
		dp[i][0] = dp_max+1;
	}
	dp[n-1][1] = 1;
	for(int i=n-2; 0<=i; i--)
	{
		dp_max = 0;
		for(int j=n-1; i<j; j--)
		{
			if (arr[j] < arr[i] && dp_max < dp[j][1])
				dp_max = dp[j][1];
		}
		dp[i][1] = dp_max+1;
	}
	ret = 0;
	for(int i=0; i<n; i++)
		if (ret < dp[i][0]+dp[i][1])
			ret = dp[i][0]+dp[i][1];
	cout<<ret-1<<'\n';
}