#include <iostream>
using namespace std;
#define	INF 987654321

int		box[1002], dp[1002];
int		n, ans;

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>box[i];
	for(int i=2; i<n; i++)
		dp[i] = INF;
	ans = 1;  // 해 초기화
	dp[1] = box[0];  // 첫번째 값으로 초기화
	for(int i=1; i<n; i++)
		for(int j=ans; 0<=j; j--)  // 구한 해부터 내려가면서 반복
			// 현재상자(box[i])보다 작은값을 가진 상자(dp[j])를 발견하면
			if (dp[j]<box[i])
			{
				dp[j+1] = min(box[i], dp[j+1]);  // 값을 비교하며 dp값 변경
				ans = max(ans, j+1);  // 값을 비교하며 해 변경
				break ;
			}
	cout<<ans<<'\n';
}