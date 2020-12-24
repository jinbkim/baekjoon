#include <iostream>
#include <cstring>
using namespace std;

bool	visit[10];
int		ans[10];
int		n;

void	brute_force(int idx)
{
	if (n < idx)
	{
		for(int i=1; i<=n; i++)
			cout<<ans[i]<<" ";  // 순열 출력
		cout<<'\n';
		return ;
	}
	for(int i=1; i<=n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;  // 백트래킹
			ans[idx] = i;  // 순열 넣기
			brute_force(idx+1);  // 다음 인덱스 탐색
			visit[i] = 0;  // 백트래킹
		}
	}
}

int		main(void)
{
	cin>>n;
	memset(visit, 0, sizeof(visit));
	brute_force(1);
}