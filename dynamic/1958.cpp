#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	str1, str2, str3;
int		dp[102][102][102];

int		main(void)
{
	cin>>str1>>str2>>str3;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=str1.size(); i++)
		for(int j=1; j<=str2.size(); j++)
			for(int k=1; k<=str3.size(); k++)
			{
				if (str1[i-1]==str2[j-1] && str2[j-1]==str3[k-1])
					dp[i][j][k] = dp[i-1][j-1][k-1]+1;
				else
					dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
			}
	cout<<dp[str1.size()][str2.size()][str3.size()];
}