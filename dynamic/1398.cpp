#include <iostream>
#include <vector>
using namespace std;

long long	car;
int			dp[102];  // dp[i] :1원, 10원, 25원 짜리동전으로 i원을 만들때 동전개수의 최소값
int			coin[3] = {10, 25};
int			t, sum;

int		main(void)
{
	// dp[1] ~ dp[99] 구하기
	for(int i=1; i<100; i++)
	{
		dp[i] = dp[i-1]+1;
		for(int j=0; j<2; j++)
			if (coin[j] <= i)
				dp[i] = min(dp[i], dp[i-coin[j]]+1);
	}

	// 100씩 끊어서 계산하기
	// if car == 123456, sum = dp[12]+dp[34]+dp[56]
	cin>>t;
	for(int i=0; i<t; i++)
	{
		vector<int>	vec;
	
		cin>>car;
		while (0 < car)
		{
			vec.push_back(car%100);
			car /= 100;
		}
		sum = 0;
		for(int i=0; i<vec.size(); i++)
			sum += dp[vec[i]];
		cout<<sum<<'\n';
	}
}