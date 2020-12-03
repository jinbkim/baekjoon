#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int>	vec[102];
bool	visit[102];
int		n, from, to, m, a, b;

void	bfs()
{
	queue < pair <int, int> >	q;
	int	cur, idx;

	q.push(make_pair(from, 0));
	while (!q.empty())
	{
		cur = q.front().first;
		idx = q.front().second;
		visit[cur] = true;
		q.pop();
		if (cur == to)
		{
			cout<<idx<<'\n';
			exit(0);
		}
		for(int i=0; i<vec[cur].size(); i++)
			if (!visit[vec[cur][i]])
				q.push(make_pair(vec[cur][i], idx+1));
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
	bfs();
	cout<<-1<<'\n';
}