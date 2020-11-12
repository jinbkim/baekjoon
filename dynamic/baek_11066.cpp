#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define	MAX	502

int		dp[MAX][MAX];
int		sum[MAX];
int		arr[MAX];
int		t, k;

void	init(void)
{
	memset(sum, 0, sizeof(sum));
	memset(dp, 0, sizeof(dp));
}

int		file_comb(void)
{
	int		ret;

	for(int i=1; i<=k-1; i++)
		for(int j=1; j<=k-i; j++)
		{
			dp[j][j+i] = 987654321;
			for(int mid=j; mid<j+i; mid++)
				dp[j][j+i] = min(dp[j][j+i], dp[j][mid]+dp[mid+1][j+i]+sum[j+i]-sum[j-1]);
		}
	return (dp[1][k]);
}



int		main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>k;
		init();	
		for(int i=1; i<=k; i++)
		{
			cin>>arr[i];
			sum[i] = sum[i-1]+arr[i];
		}
		cout<<file_comb()<<'\n';
	}
}