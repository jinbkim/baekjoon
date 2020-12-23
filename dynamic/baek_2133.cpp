#include <iostream>
#include <cstring>
using namespace std;

int		dp[32];
int		n;

int		solve(void)
{
	memset(dp, 0, sizeof(dp));
	dp[2] = 3;
	for(int i=4; i<=n; i+=2)
	{
		// dp[2] = 3, dp[2]가 왼쪽에, dp[i-2]가 오른쪽에있는 상태의 조합으로 만들어지는 경우의수
		// 앞으로 남은 경우의수는 왼쪽에 새로운모양이 있는경우
		dp[i] = 3 * dp[i-2];
		for(int j=i-4; 2<=j; j-=2)
			// 왼쪽에 가로의 크기가 i-j인 새로운모양이, dp[j]가 오른쪽에있는 상태의 조합으로 만들어지는 경우의수
			dp[i] += 2 * dp[j];
		dp[i] += 2;  // 새로 만들어지는 새로운모양
	}
	return(dp[n]);
}

int		main(void)
{
	cin>>n;
	if (n % 2)  // 홀수의 경우의 수는 0
		cout<<0<<'\n';
	else
		cout<<solve()<<'\n';
}