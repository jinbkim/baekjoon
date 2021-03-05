#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// dp[i][j] : 1번부터 i번 물건이 있고 배낭의 최대 용량이 j일때, 배낭에 담긴 물건가격들의 합이 최대가 되는값
int	dp[102][100002];
int	w[102];  // 물건의 무게
int	v[102];  // 물건의 가격
int	n, k;

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>k;
	for (int i=1; i<=n; i++)
		cin>>w[i]>>v[i];
	for (int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
		{
			dp[i][j] = dp[i-1][j];
			if (0<=j-w[i])
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
		}
	cout<<dp[n][k];
}