#include <iostream>
#include <cstring>
using namespace std;

// dp[i][j] : 1번부터 i번 물건이 있고 배낭의 최대 용량이 j일때, 배낭에 담긴 물건가격들의 합이 최대가 되는값
int	dp[102][100002];
int	w[102];  // 물건의 무게
int	v[102];  // 물건의 가격
int	n, k;

int		knapsack(int n, int k)
{
	if (!n || k<=0)
		return (0);
	if (dp[n][k])
		return (dp[n][k]);
	dp[n][k] = knapsack(n-1, k);
	if (0 <= k-w[n])
		dp[n][k] = max(dp[n][k], knapsack(n-1, k-w[n])+v[n]);
	return (dp[n][k]);
}

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>w[i]>>v[i];
	cout<<knapsack(n, k)<<'\n';
}