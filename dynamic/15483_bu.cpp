#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	s1, s2;
int		dp[1002][1002];  // dp[i][j] : s1[0]~s[i-1]문자열과 s2[0]~s2[j-1]문자열의 최소편집 횟수

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>s1>>s2;
	for(int i=0; i<=s1.size(); i++)
		for(int j=0; j<=s2.size(); j++)
		{
			if(!i)
				dp[i][j] = j;
			else if (!j)
				dp[i][j] = i;
			else if (s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
		}
	cout<<dp[s1.size()][s2.size()];
}