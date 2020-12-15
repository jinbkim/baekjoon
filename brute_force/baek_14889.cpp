#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool	visit[22];
int		s[22][22];
int		n, start, link, ret=987654321;

void	solve(void)
{
	start = 0;
	link = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if (visit[i] && visit[j])  // i번째와 j번째 사람이 start팀일때
				start += s[i][j];
			else if (!visit[i] && !visit[j])  // i번째와 j번째 사람이 link팀일때
				link += s[i][j];
		}
	ret = min(ret, abs(start-link));  // 팀의 능력치의 최소값 변경
}

void	dfs(int idx, int sel)  // idx : 탐색하는 인덱스, sel : 이전까지 선택한 개수
{
	if (n < idx)  // 모두 탐색했을때
	{
		if (sel == n/2)  // 절반을 선택했을때
			solve();
		return ;
	}
	visit[idx] = true;
	dfs(idx+1, sel+1);  // idx번째 사람을 선택했을 경우
	visit[idx] = false;
	dfs(idx+1, sel);  // idx번째 사람을 선택하지 않았을 경우
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>s[i][j];
	memset(visit, 0, sizeof(visit));  // 방문 초기화
	dfs(1, 0);  // 인덱스가 1인곳부터 방문
	cout<<ret<<'\n';
}