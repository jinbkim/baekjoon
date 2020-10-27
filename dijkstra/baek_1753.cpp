#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
vector < pair<int, int> >	vec[20001];
int		min_d[20001];
int		INF = 2147483647;
int		v, e, k;

void	dijkstar(int start)
{
	priority_queue< pair<int, int> >	pq;

	min_d[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int	vtx, edge;

		vtx = pq.top().second;
		edge = -pq.top().first;
		pq.pop();
		if (min_d[vtx] < edge)
			continue ;
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
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>v>>e>>k;
	for(int i=0; i<e; i++)
	{
		int	in[3];

		cin>>in[0]>>in[1]>>in[2];
		vec[in[0]].push_back(make_pair(in[1], in[2]));
	}
	for(int i=1; i<=v; i++)
		min_d[i] = INF;
	dijkstar(k);
	for(int i=1; i<=v; i++)
	{
		if (min_d[i] == INF)
			cout<<"INF\n";
		else
			cout<<min_d[i]<<'\n';
	}
}