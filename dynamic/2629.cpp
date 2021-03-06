#include <iostream>
#include <cstring>
using namespace std;

bool	dp[32][40002];
int		w[32];
int 	weight, bead, sum=0, b;

int		main(void)
{
	cin>>weight;
	for(int i=1; i<=weight; i++)
		cin>>w[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=1; i<=weight; i++)
	{
		sum += w[i];
		for(int j=0; j<=sum; j++)
		{
			if (dp[i-1][j])
			{
				dp[i][abs(w[i]-j)] = 1;
				dp[i][abs(w[i]+j)] = 1;
				dp[i][j] = 1;
			}
		}
	}
	cin>>bead;
	for(int i=1; i<=bead; i++)
	{
		cin>>b;
		if (dp[weight][b])
			cout<<'Y'<<' ';
		else
			cout<<'N'<<' ';
	}
}