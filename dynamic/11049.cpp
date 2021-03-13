#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int	dp[502][502];  // dp[i][j] : i번째 행렬부터 j번째 행렬까지의 곱셈 연산의 최소값
int	row[502];
int	col[502];
int	n;

int		solve(int y, int x)
{
	int ret = 987654321;

	if (dp[y][x])
		return (dp[y][x]);
	if (x <= y)
		return (0);
	for(int i=y; i<x; i++)
		ret = min(ret, solve(y, i)+row[y]*col[i]*col[x]+solve(i+1, x));
	return (dp[y][x] = ret);
}

int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>row[i]>>col[i];
	cout<<solve(0, n-1);
}