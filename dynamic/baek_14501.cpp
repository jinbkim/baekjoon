#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int		t[25], p[25], dp[25];
int		n;

int		main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>t[i]>>p[i];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++)
	{
		dp[i] = max(dp[i], dp[i-1]);  // 이전의 비용이 더크면 현재값 변경
		dp[i+t[i]]  = max(dp[i+t[i]], dp[i]+p[i]);  // t일 후에 최대수익 변경
	}
	cout<<max(dp[n], dp[n+1])<<'\n';
}