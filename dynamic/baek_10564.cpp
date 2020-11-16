#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX	5002

bool	dp[MAX][MAX];
int		score[12];
int		t, sum, n, ret;

void	init(void)
{
	memset(dp, false, sizeof(dp));
}

void	solve(int a, int b)
{
	if (dp[a][b] || sum < b)
		return ;
	dp[a][b] = true;
	for(int i=0; i<n; i++)
		solve(a+score[i], a+score[i]+b);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>sum>>n;
		for(int j=0; j<n; j++)
			cin>>score[j];
		init();
		solve(0, 0);
		ret = -1;
		for(int i=0; i<=sum; i++)
			if (dp[i][sum])
				ret = i;
		cout<<ret<<'\n';
	}
}