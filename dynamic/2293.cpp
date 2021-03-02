#include <iostream>
#include <cstring>
using namespace std;

int	dp[100002];  // dp[i] : i원을 만들수있는 동전조합의 경우의수
int	coin[102];  // coin[i] : i번째 동전의 가치
int	n;  // 동전종류의 개수
int	k;  // 구하려는 답 : k원을 만들수있는 동전조합의 경우의수

int		main(void)
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>coin[i];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
			if (coin[i] <= j)  // j<coin[i] 이면, dp[j]=0
				dp[j] += dp[j-coin[i]];
	cout<<dp[k];
}