#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	str1, str2;
int		dp[302][302];
int		n, m, minVal, diff;

int		editDistance(int i, int j)
{
	if (dp[i][j])
		return (dp[i][j]);
	if (i<=0 || j<=0)
		return (0);
	minVal = min(min(editDistance(i-1, j-1), editDistance(i-1, j)), editDistance(i, j-1));
	diff = abs(str1[i-1]-str2[j-1]);
	if (i == 1)
		return (dp[i][j] = dp[i][j-1]+diff);
	else if (j == 1)
		return (dp[i][j] = dp[i-1][j]+diff);
	return (dp[i][j] = minVal+diff);
}

int		main(void)
{
	cin>>n>>m>>str1>>str2;
	memset(dp, 0, sizeof(dp));
	cout<<editDistance(n, m);
}