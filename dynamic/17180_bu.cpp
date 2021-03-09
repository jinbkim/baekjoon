#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	str1, str2;
int		dp[302][302];
int		n, m, minVal, diff;

int		main(void)
{
	cin>>n>>m>>str1>>str2;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			minVal = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
			diff = abs(str1[i-1]-str2[j-1]);
			if (i == 1)
				dp[i][j] = dp[i][j-1]+diff;
			else if (j == 1)
				dp[i][j] = dp[i-1][j]+diff;
			else
				dp[i][j] = minVal+diff;
		}
	cout<<dp[n][m];
}