#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char	arr[1002][1002];
int		ans[1002][1002];
int		n, m, ret=0;

int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
			if (arr[i][j] == '1')
			{
				if (!i || !j)  // 사이드면
					ans[i][j] = 1;
				// 왼쪽, 위, 왼쪽위대각선 이 모두 1일때
				else if (arr[i-1][j] && arr[i][j-1] && arr[i-1][j-1])
					// 왼쪽, 위, 왼쪽위대각선 중 최소값+1
					ans[i][j] = min(min(ans[i-1][j-1], ans[i-1][j]), ans[i][j-1]) + 1;
				else  // 왼쪽, 위, 왼쪽위대각 한곳이라도 0이면
					ans[i][j] = 1;
			}
			else
				ans[i][j] = 0;
			ret = max(ret, ans[i][j]);
		}
	cout<<ret*ret;
}