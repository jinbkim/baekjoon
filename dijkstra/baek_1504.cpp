#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF	987654321
#define	MAX	802

vector< pair<int, int> >	vec[MAX];
long long	min_d[MAX];
int		n, e, from, to, cost, edge1, edge2;

int		dijkstra(int start, int end)
{
	priority_queue< pair<int, int> >	pq;
	int	vtx1, vtx2, edge1, edge2;

	for(int i=1; i<=n; i++)
		min_d[i] = INF;
	min_d[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		vtx1 = pq.top().second;
		edge1 = -pq.top().first;
		pq.pop();
		if (min_d[vtx1] < edge1)
			continue ;
		for(int i=0; i<vec[vtx1].size(); i++)
		{
			vtx2 = vec[vtx1][i].first;
			edge2 = vec[vtx1][i].second+edge1;
			if (edge2 < min_d[vtx2])
			{
				min_d[vtx2] = edge2;
				pq.push(make_pair(-edge2, vtx2));
			}
		}
	}
	return (min_d[end]);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		path[6];
	int		ret1, ret2;

	cin>>n>>e;
	for(int i=0; i<e; i++)
	{
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
		vec[to].push_back(make_pair(from, cost));
	}
	cin>>edge1>>edge2;
	path[0] = dijkstra(1, edge1);
	path[1] = dijkstra(edge1, edge2);
	path[2] = dijkstra(edge2, n);
	path[3] = dijkstra(1, edge2);
	path[4] = dijkstra(edge2, edge1);
	path[5] = dijkstra(edge1, n);
	ret1 = 0;
	ret2 = 0;
	for(int i=0; i<3; i++)
	{
		if(path[i] == INF)
		{
			ret1 = INF;
			break ;
		}
		ret1 += path[i];
	}
	for(int i=3; i<6; i++)
	{
		if(path[i] == INF)
		{
			ret2 = INF;
			break ;
		}
		ret2 += path[i];
	}
	if (ret1 == INF && ret2 == INF)
	{
		cout<<-1<<'\n';
		return (0);
	}
	cout<<min(ret1, ret2)<<'\n';
}