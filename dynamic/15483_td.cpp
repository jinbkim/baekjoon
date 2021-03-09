#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	s1, s2;
int		dp[1002][1002];  // dp[i][j] : s1[0]~s[i-1]문자열과 s2[0]~s2[j-1]문자열의 최소편집 횟수

int		editDistance(int i, int j)
{
	if (dp[i][j] != -1)
		return (dp[i][j]);
	if (!i)
		return (dp[i][j] = j);
	else if (!j)
		return (dp[i][j] = i);
	else if (s1[i-1] == s2[j-1])
		dp[i][j] = editDistance(i-1, j-1);
	else
		dp[i][j] = min(min(editDistance(i-1, j-1), editDistance(i-1, j)), editDistance(i, j-1)) + 1;
	return (dp[i][j]);
}

int		main(void)
{
	memset(dp, -1, sizeof(dp));
	cin>>s1>>s2;
	cout<<editDistance(s1.size(), s2.size());
}