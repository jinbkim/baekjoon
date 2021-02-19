#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define	MAX	1002

vector<int>	vec[MAX];  // 인접리스트
int	arr[MAX][MAX];  // 인접행렬
int	visit[MAX];
int	n, m, start, v1, v2;

void	dfs(int v)
{
	if (visit[v])
		return ;
	visit[v] = 1;
	cout<<v<<' ';
	for(int i=1; i<=n; i++)
		if (arr[v][i])
			dfs(i);
}

void	bfs(int v)
{
	queue<int>	q;

	q.push(start);
	while (!q.empty())
	{
		v1 = q.front();
		q.pop();
		if (visit[v1])
			continue ;
		visit[v1] = 1;
		cout<<v1<<' ';
		for(int i=0; i<vec[v1].size(); i++)
			q.push(vec[v1][i]);
	}
}

int		main(void)
{
	cin>>n>>m>>start;
	memset(arr, 0, sizeof(arr));
	for(int i=0; i<m; i++)
	{
		cin>>v1>>v2;
		arr[v1][v2] = 1;  // 인접행렬 연결
		arr[v2][v1] = 1;;  // 인접행렬 연결
		vec[v1].push_back(v2);  // 인접리스트 연결
		vec[v2].push_back(v1);  // 인접리스트 연결
	}
	memset(visit, 0, sizeof(visit));
	dfs(start);
	cout<<'\n';
	memset(visit, 0, sizeof(visit));
	for(int i=1; i<=n; i++)
		sort(vec[i].begin(), vec[i].end());
	bfs(start);
}