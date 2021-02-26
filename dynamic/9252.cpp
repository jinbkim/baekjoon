// 같은 문자가 나오면
// dp[i][j] = dp[i-1][j-1]+1;

// 다른 문자가 나오면
// dp[i][j] = max (dp[i-1][j], dp[i][j-1]);

#include <iostream>
#include <cstring>
using namespace std;

string		str1, str2;
string		dpStr[1002][1002];
int			dp[1002][1002];

int		main(void)
{
	cin>>str1>>str2;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=str1.size(); i++)
	{
		for(int j=1; j<=str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
				dpStr[i][j] = dpStr[i-1][j-1]+ str1[i-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				if (dp[i-1][j] < dp[i][j-1])
				{
					dp[i][j] = dp[i][j-1];
					dpStr[i][j] = dpStr[i][j-1];
				}
				else
				{
					dp[i][j] = dp[i-1][j];
					dpStr[i][j] = dpStr[i-1][j];
				}
			}
		}
	}
	cout<<dp[str1.size()][str2.size()]<<'\n';
	cout<<dpStr[str1.size()][str2.size()]<<'\n';
}