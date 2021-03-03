#include <iostream>
#include <cstring>
using namespace std;

int	dp[10002];  // dp[i] : i원을 만들수있는 동전조합의 경우의수
int	t;  // 구하려는 답 : t원을 만들수있는 동전조합의 경우의수
int k;  // 동전종류의 개수
int p, n;  // 동전의 금액과 개수
int	sum;

int		main(void)
{
	cin>>t>>k;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i<k; i++)
	{
		cin>>p>>n;
		for(int j=t; 0<j; j--)
		{
			for(int l=1; l<=n; l++)
			{
				sum = p*l;
				if (sum<=j && dp[j-sum])
					dp[j] += dp[j-sum];
			}
		}
	}
	cout<<dp[t];
}