#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int		dp[5002];
int		n;

int		main(void)
{
	cin>>n;
	for(int i=3; i<=n; i++)
		dp[i] = INF;
	dp[3] = 1;  // 초기값 설정
	dp[5] = 1;  // 초기값 설정
	for(int i=3; i<=n; i++)
		if (dp[i] != -1)
		{
			// 다음번에 3킬로그램 봉지를 넣었을때의 봉지의 최소값 최신화
			dp[i+3] = min(dp[i+3], dp[i]+1);
			// 다음번에 5킬로그램 봉지를 넣었을때의 봉지의 최소값 최신화
			dp[i+5] = min(dp[i+5], dp[i]+1);
		}
	if (dp[n] == INF)
		cout<<-1<<'\n';
	else
		cout<<dp[n]<<'\n';
}