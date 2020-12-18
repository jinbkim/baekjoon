#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool	visit[10];  // 방문체크 플래그
int		ans[10];  // 계산할 데이터를 모아두는곳
int		arr[10];
int		n, ret=0;

int		cal(void)
{
	int		ret=0;

	for(int i=1; i<n; i++)
		ret += abs(ans[i]-ans[i-1]);  // 문제에서 원하는 계산
	return (ret);
}

void	brute_force(int idx)
{
	if (idx == n)
	{
		ret = max(ret, cal());  // 전에 구한 최대값보다 큰값이 나오면 해답 변경
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if (!visit[i])  // 방문 안했으면
		{
			visit[i] = true;  // 방문처리 (백트래킹)
			ans[idx] = arr[i];  // 정답배열에 계산할 데이터 넣기
			brute_force(idx+1);  // 다음 인덱스 넣을 데이터 탐색
			visit[i] = 0;  // 미방문처리 (백트래킹)
		}
	}
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	memset(visit, 0, sizeof(visit));
	brute_force(0);
	cout<<ret<<'\n';
}