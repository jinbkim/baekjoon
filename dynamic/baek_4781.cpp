#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

float	price_d[5002];
float	m_d;
int		dp[10002];
int		calorie[5002];
int		price[5002];
int		n, m;

void	init(void)
{
	memset(dp, -1, sizeof(dp));
	m = m_d * 100;
}

int		solve(void)
{
	for(int i=0; i<n; i++)
		dp[price[i]] = calorie[i];
	for(int i=0; i<=m; i++)
		for(int j=0; j<n; j++)
			if (0 <= i-price[j] && dp[i-price[j]] != -1)
				dp[i] = max(dp[i], dp[i-price[j]]+calorie[j]);
	sort(dp, dp+m+1);
	return(dp[m]);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while (1)
	{
		cin>>n>>m_d;
		if (!n && !m_d)
			break ;
		init();
		for(int i=0; i<n; i++)
		{
			cin>>calorie[i]>>price_d[i];
			price[i] = price_d[i]*100;
		}
		cout<<solve()<<'\n';
	}
}