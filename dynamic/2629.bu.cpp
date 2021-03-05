#include <iostream>
#include <cstring>
using namespace std;
#define	MAX	40002

bool	dp[MAX];
int		w[32];
int 	weight, bead, sum=0, b;

int		main(void)
{
	cin>>weight;
	for(int i=1; i<=weight; i++)
		cin>>w[i];
	cin>>bead;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=1; i<=weight; i++)
	{
		sum += w[i];
		for(int j=1; j<w[i]; j++)
			if (dp[j])
				dp[w[i]-j] = 1;
		for(int j=0; j<=sum-w[i]; j++)
			if (dp[j])
				dp[w[i]+j] = 1;
	}
	for(int i=1; i<=bead; i++)
	{
		cin>>b;
		if (dp[b])
			cout<<'Y'<<' ';
		else
			cout<<'N'<<' ';
	}
}