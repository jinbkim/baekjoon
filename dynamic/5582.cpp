#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	str1, str2;
int		dp[4002][4002];
int		ans=0;

int		main(void)
{
	cin>>str1>>str2;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=str1.size(); i++)
	{
		for(int j=1; j<=str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = 0;
			ans = max(ans, dp[i][j]);
		}
	}
	cout<<ans;
}