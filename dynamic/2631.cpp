#include <iostream>
#include <algorithm>
using namespace std;

int	dp[202];  // dp[i] : 인덱스 0~i 에서 최장 증가 부분수열의 크기가 저장됨
int	child[202];
int	n;

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>child[i];
	for(int i=0; i<n; i++)
	{
		dp[i] = 1;
		for(int j=0; j<i; j++)
			if (child[j] < child[i])
				dp[i] = max(dp[i], dp[j]+1);
	}
	sort(dp, dp+n);
	cout<<n-dp[n-1];
}