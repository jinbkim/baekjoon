#include <iostream>
using namespace std;

long long	dp[32][32];  // dp[i][j] : i는 한조각, j는 반조각일때 만들수 있는 문자열의 경우의수
long long	n, idx;  

int		main(void)
{
	for(int i=0; i<=30; i++)
		for(int j=0; j<=30; j++)
		{
			if (!i)  // 한조각이 0개일때
				dp[i][j] = 1;  // 경우의 수는 1
			else if (!j)  // 반조각이 0개일때
				dp[i][j] = dp[i-1][1];  // 일단 한조각 쪼개고 시작함
			else
				dp[i][j] = dp[i-1][j+1]+dp[i][j-1];  // dp[i][j] : 한조각을 쪼갠경우+반조각을 먹은경우
		}
	while (1)
	{
		cin>>idx;
		if (!idx)
			break ;
		cout<<dp[idx-1][1]<<'\n';
	}
}