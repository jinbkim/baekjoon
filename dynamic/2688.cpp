#include <iostream>
using namespace std;

long long	dp[66][10];  // dp[i][j] : i자리 수의 맨뒤가 j가 나오는 경우의수
long long	t;
long long	n;

int		main(void)
{
	for(int i=1; i<=65; i++)
		for(int j=0; j<=9; j++)
		{
			if (i==1 || !j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		cout<<dp[n+1][9]<<'\n';
	}
}