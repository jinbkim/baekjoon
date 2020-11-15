#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

string	str;
char	boj[3][2] = {{'B','O'},{'O','J'},{'J','B'}};
int		dp[1002];
int		n;

void	init(void)
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
}

void	solve(void)
{
	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			for(int k=0; k<3; k++)
				if (str[j]==boj[k][0] && str[i]==boj[k][1] && dp[j]!=-1)
				{
					if (dp[i] == -1)
						dp[i] = (i-j)*(i-j)+dp[j];
					else	
						dp[i] = min(dp[i] ,(i-j)*(i-j)+dp[j]);
				}
}



int		main(void)
{
	cin>>n>>str;
	init();
	solve();
	cout<<dp[n-1]<<'\n';
}