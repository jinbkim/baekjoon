#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

vector < pair<int, int> >	vec[802];
int		min_d[802];
int		INF = 2147483647;
int		n, m;

int		dijkstar(int start, int end)
{
	priority_queue< pair<int, int> >	pq;
	
	for(int i=1; i<=n; i++)
		min_d[i] = INF;
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
	return (min_d[end]);
}



int		main(void)
{
	int		in[3];
	int		ret[6];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>in[0]>>in[1]>>in[2];
		vec[in[0]].push_back(make_pair(in[1], in[2]));
		vec[in[1]].push_back(make_pair(in[0], in[2]));
	}
	cin>>in[0]>>in[1];
	ret[0] = dijkstar(1, in[0]);
	ret[1] = dijkstar(in[0], in[1]);
	ret[2] = dijkstar(in[1], n);
	ret[3] = dijkstar(1, in[1]);
	ret[4] = dijkstar(in[1], in[0]);
	ret[5] = dijkstar(in[0], n);
	in[0] = 0;
	in[1] = 0;
	for(int i=0; i<3; i++)
	{
		if (ret[i] == INF)
		{
			in[0] = INF;
			break ;
		}
		else
			in[0] += ret[i];
	}
	for(int i=3; i<6; i++)
	{
		if (ret[i] == INF)
		{
			in[1] = INF;
			break ;
		}
		else
			in[1] += ret[i];
	}
	if (in[0] == INF && in[1] == INF)
		cout<<-1<<'\n';
	else
		cout<<min(in[0], in[1])<<'\n';
}