#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int>		vec[10002];
bool	visit[10002];
int		depth[10002];
int		n, m, from, to, big=0;

void	dfs(int idx)
{
	if (visit[idx])  // 재방문 x
		return ;
	visit[idx] = true;  // 방문 표시
	depth[idx]++;  // 크기가 클수록 높이가 높음
	for(int i=0; i<vec[idx].size(); i++)
		if (!visit[vec[idx][i]])  // 방문 안한곳만 재방문
			dfs(vec[idx][i]);
}



int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to;
		vec[from].push_back(to);
	}
	memset(depth, 0, sizeof(depth));
	for(int i=1; i<=n; i++)
	{
		memset(visit, 0, sizeof(visit));  // 루트노드가 바뀔때마다 방문초기화
		dfs(i);
	}
	for(int i=1; i<=n; i++)
		big = max(big, depth[i]);  // 깊이의 최대값 찾기
	for(int i=1; i<=n; i++)
		if (big == depth[i])  // 깊이가 최대일때만 출력
			cout<<i<<" ";
}