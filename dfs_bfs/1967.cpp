#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector< pair<int, int> >	vec[10002];
bool	visit[10002];
int		n, a, b, w, ret=0;

void	dfs(int i, int w)
{
	visit[i] = 1;  // 방문표시
	ret = max(ret, w);  // 트리의 지름 갱신 
	for(int j=0; j<vec[i].size(); j++)
		if (!visit[vec[i][j].first])  // 방문하지 않았으면
			dfs(vec[i][j].first, w+vec[i][j].second);
}

int		main(void)
{
	cin>>n;
	for(int i=1; i<=n-1; i++)
	{
		cin>>a>>b>>w;
		vec[a].push_back(make_pair(b, w));  // a노드와 b노드의 간선의 가중치는 w
		vec[b].push_back(make_pair(a, w));  // a노드와 b노드의 간선의 가중치는 w
	}
	for(int i=1; i<=n; i++)
	{
		memset(visit, 0, sizeof(visit));
		dfs(i, 0);
	}
	cout<<ret;
}