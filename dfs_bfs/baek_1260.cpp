#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<int>	vec[1001];
int		n, m, v, edge1, edge2;
int		visted[1001];

void	init(void)
{
	memset(visted, 0, sizeof(visted));
}

void	dfs(int v)
{
	if (visted[v])
		return ;
	visted[v] = true;
	cout<<v<<' ';
	for(long unsigned int i=0; i<vec[v].size(); i++)
		dfs(vec[v][i]);
}

void	bfs(int v)
{
	queue<int>	q;

	visted[v] = true;
	q.push(v);
	while (!q.empty())
	{
		edge1 = q.front();
		q.pop();
		cout<<edge1<<' ';
		for(long unsigned int i=0; i<vec[edge1].size(); i++)
		{
			edge2 = vec[edge1][i];
			if (!visted[edge2])
			{
				q.push(edge2);
				visted[edge2] = true;
			}
		}
	}
}



int		main(void)
{
	init();
	cin>>n>>m>>v;
	for(int i=0; i<m; i++)
	{
		cin>>edge1>>edge2;
		vec[edge1].push_back(edge2);
		vec[edge2].push_back(edge1);
	}
	for(int i=0; i<n; i++)
		sort(vec[i].begin(), vec[i].end());
	dfs(v);
	init();
	cout<<'\n';
	bfs(v);
	cout<<'\n';
}