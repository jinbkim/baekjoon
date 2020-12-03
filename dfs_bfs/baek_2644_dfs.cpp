#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>	vec[102];
bool	visit[102];
int		n, from, to, m, a, b;

void	dfs(int cur, int idx)
{
	if (cur == to)
	{
		cout<<idx<<'\n';
		exit(0);
	}
	for(int i=0; i<vec[cur].size(); i++)
	{
		if (!visit[vec[cur][i]])
		{
			visit[vec[cur][i]] = true; 
			dfs(vec[cur][i], idx+1);
			visit[vec[cur][i]] = false; 
		}
	}
}

int		main(void)
{
	memset(visit, 0, sizeof(visit));
	cin>>n>>from>>to>>m;
	for(int i=0; i<m; i++)
	{
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(from, 0);
	cout<<-1<<'\n';
}