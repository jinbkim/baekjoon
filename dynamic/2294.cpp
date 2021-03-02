#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int	dp[100002];  // dp[i] : n가지 종류의 동전으로 i원을 만들수있는 동전개수의 최소값
int	coin[102];  // coin[i] : i번째 동전의 가치 
int	n;  // 동전종류의 개수
int	k;  // 구하려는 답 : k원을 만들때, 동전의 개수가 최소값인 경우 구하기

int		main(void)
{
	cin>>n>>k;
	for(int i=1; i<=n; i++)
		cin>>coin[i];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i=1; i<=n ; i++)
		for(int j=1; j<=k; j++)
        	// j<coin[i] 이거나 dp[j-coin[i]==-1 이면, dp[j]=-1
			if (coin[i]<=j && dp[j-coin[i]]!=-1)
			{
				if (dp[j] == -1)
					dp[j] = dp[j-coin[i]]+1;
				else
					dp[j] = min(dp[j], dp[j-coin[i]]+1);
			}
	cout<<dp[k];
}