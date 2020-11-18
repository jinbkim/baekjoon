#include <iostream>
#include <cstring>
using namespace std;

#define MAX	2002

bool	dp[MAX][MAX];
int		arr[MAX];
int		n, m, s, e;

void	init(void)
{
	memset(dp, 0, sizeof(dp));
}

void	solve(void)
{
	for(int i=1; i<=n; i++)
	{
		dp[i][i] = true;
		if (arr[i] == arr[i+1])
			dp[i][i+1] = true;
	}
	for(int i=1; i<=n-1; i++)
		for(int j=i+2; j<=n; j++)
			if (dp[j-i][j-1] && (arr[j-i-1]==arr[j]))
				dp[j-i-1][j] = true;
}



int		main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	init();
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	solve();
	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>s>>e;
		cout<<dp[s][e]<<'\n';
	}
}