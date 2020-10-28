#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX	1002
#define	INF	987654321

vector< pair<int, int> >	vec[MAX];
long long	min_d[MAX];
int		n, m, from, to, cost, city_s, city_e;

void	init(void)
{
	for(int i=1; i<=n; i++)
		min_d[i] = INF;
	min_d[city_s] = 0;
}

int		dijkstra(int s, int e)
{
	priority_queue< pair<int, int> >	pq;
	int	vtx1, vtx2, edge1, edge2;

	pq.push(make_pair(0, s));
	while(!pq.empty())
	{
		vtx1 = pq.top().second;
		edge1 = -pq.top().first;
		pq.pop();
		if (min_d[vtx1] < edge1)
			continue ;
		for(int i=0; i<vec[vtx1].size(); i++)
		{
			vtx2 = vec[vtx1][i].first;
			edge2 = vec[vtx1][i].second+min_d[vtx1];
			if (edge2 < min_d[vtx2])
			{
				min_d[vtx2] = edge2;
				pq.push(make_pair(-edge2, vtx2));
			}
		}
	}
	return (min_d[e]);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
	}
	cin>>city_s>>city_e;
	init();
	cout<<dijkstra(city_s, city_e)<<'\n';
}