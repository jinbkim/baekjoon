#include <iostream>
#include <algorithm>
using namespace std;

int	arr[1000002];
int	dp[1000002];  // dp[i] : 인덱스가 0~i 까지 가장 긴 증가하는 부분 수열의 크기가 저장됨
int	n;

int		main(void)
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++)
	{
		dp[i] = 1;
		for(int j=0; j<i; j++)
			if (arr[j] < arr[i])  // 왼쪽에 있는 숫자가 작으면
				dp[i] = max(dp[i] ,dp[j]+1); // dp값 갱신
	}
	sort(dp, dp+n);
	cout<<dp[n-1];  // 가장 큰값 출력
}