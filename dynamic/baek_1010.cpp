#include <iostream>
#include <cstring>
using namespace std;

long long	dp[32][32];
long long	t, n, m;

long long	combi(long long m, long long n)
{
	if (!n || !m || (n == m))  // 기저사례 : 더이상 쪼개지지않은 작은문제
	{
		dp[m][n] = 1;
		return (dp[m][n]);
	}
	if (!dp[m][n])  // 조합공식
		dp[m][n] = combi(m-1,n-1)+combi(m-1,n);
	return (dp[m][n]);
}



int				main(void)
{
	memset(dp, 0, sizeof(dp));  // 아직 풀지않은 문제는 0으로 초기화
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n>>m;
		cout<<combi(m, n)<<'\n';  // top-down : 큰 문제를 작은 문제로 쪼개면서 품 (재귀)
	}
}