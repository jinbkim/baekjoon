#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector< pair<int, int> >	vec[502];
int		ret[502][2];
int		min_d[502];
int		INF = 2147483647;
int		n, m;

int		dijkstra(int start, int end)
{
	priority_queue< pair<int, int> >	pq;

	for(int i=1; i<=n; i++)
		min_d[i] = INF;
	min_d[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int	vtx, edge;
		// cout<<"hi"<<'\n';
		vtx = pq.top().second;
		edge = -pq.top().first;
		pq.pop();
		if (min_d[vtx] < edge || edge < 0)
			continue ;
		// cout<<"--------------\n";
		for(int i=0; i<vec[vtx].size(); i++)
		{
			int next_vtx, next_edge;

			next_vtx = vec[vtx][i].first;
			next_edge = vec[vtx][i].second + edge;
			if (next_edge < min_d[next_vtx])
			{
				min_d[next_vtx] = next_edge;
				pq.push(make_pair(-next_edge, next_vtx));
			}
		}
	}
	// cout<<"min_d[end] : "<<min_d[end]<<'\n';
	return (min_d[end]);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		in[3];

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>in[0]>>in[1]>>in[2];
		vec[in[0]].push_back(make_pair(in[1], in[2]));
	}
	for(int i=2; i<=n; i++)
	{
		ret[i][0] = dijkstra(1, i);
		ret[i][1] = dijkstra(i, 1);
		
		if (ret[i][0] == INF)
			ret[i][0] = -1;
		ret[i][1] = dijkstra(i, 1);
		if (ret[i][0] + ret[i][1] < 0)
		{
			cout<<-1<<'\n';
			return (0);
		}
		
	}
	for(int i=2; i<=n; i++)
		cout<<ret[i][0]<<'\n';
}