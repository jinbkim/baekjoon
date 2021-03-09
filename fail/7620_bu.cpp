#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string	str1, str2;
char	ans[17002];
int		dp[17002][1700];
int		m;

// 128, 000,000
//289,000,000

int		main(void)
{
	cin>>str1>>str2;
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<=str1.size(); i++)
		for(int j=0; j<=str2.size(); j++)
		{
			if (!i)
				dp[i][j] = j;
			else if (!j)
				dp[i][j] = i;
			else if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
		}

	// for (int i=0; i<=str1.size(); i++)
	// {
	// 	for(int j=0; j<=str2.size(); j++)
	// 	{
	// 		cout<<dp[i][j]<<' ';
	// 	}
	// 	cout<<'\n';
	// }

	int	i=str1.size();
	for(int j=str2.size(); 0<j; j--)
	{
		if (!i && j)
		{
			ans[j] = 'a';
			break ;
		}
		else if (i && !j)
		{
			ans[j] = 'd';
			break ;
		}
		m = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
		if (m == dp[i-1][j-1])
		{
			if (dp[i][j] == dp[i-1][j-1])
				ans[j] = 'c';
			else
				ans[j] = 'm';
			i--;
		}
		else if (m == dp[i-1][j])
			ans[j] = 'd';
		else if (m == dp[i][j-1])
			ans[j] = 'a';
		// cout<<"i : "<<i<<", j : "<<j<<", m : "<<m<<", ans : "<<ans[j]<<'\n';
		
	}
	for(int i=1; i<=str2.size(); i++)
		cout<<ans[i]<<' '<<str2[i-1]<<'\n';
}