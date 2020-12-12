#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< pair<int, int> >	vec[1002];
int		dis[1002];
int		n, m, from, to, weight;

void	dijkstra(int start)
{
	priority_queue< pair<int, int> >	pq;
	int	v, w, next_v, next_w;

	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		v = pq.top().second;
		w = -pq.top().first;
		pq.pop();
		if (dis[v] < w)
			continue ;
		for(int i=0; i<vec[v].size(); i++)
		{
			next_v = vec[v][i].second;
			next_w = vec[v][i].first+w;
			if (next_w < dis[next_v])
			{
				dis[next_v] = next_w;
				pq.push(make_pair(-next_w, next_v));
			}
		}
	}

}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>weight;
		vec[from].push_back(make_pair(weight, to));
	}
	cin>>from>>to;
	for(int i=1; i<=n; i++)
		dis[i] = 987654321;
	dijkstra(from);
	cout<<dis[to]<<'\n';
}