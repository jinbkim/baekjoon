#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

using namespace std;
vector < pair<int, int> >	vec[801];
int		min_d[801][801];
int		INF = 2147483647;
int		n, m;

int 	dijkstar(int start, int end)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			min_d[i][j] = INF;
	// cout<<"-----------------\n";
	// cout<<"start : "<<start<<", end : "<<end<<'\n';
	priority_queue< pair<int, int> >	pq;

	min_d[start][start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int	vtx, edge;

		vtx = pq.top().second;
		edge = -pq.top().first;
		pq.pop();
		if (min_d[start][vtx] < edge || min_d[start][end] < edge)
		{
			// cout<<"pass!\n";
			continue ;
		}
		for(int i=0; i<vec[vtx].size(); i++)
		{
			int	next_vtx, next_edge;

			next_vtx = vec[vtx][i].first;
			next_edge = vec[vtx][i].second+edge;
			if (next_edge < min_d[vtx][next_vtx])
			{
				// cout<<"vtx : "<<vtx<<", next_vtx : "<<next_vtx<<'\n';
				min_d[vtx][next_vtx] = next_edge;
				pq.push(make_pair(-next_edge, next_vtx));
			}
		}
	}
	// cout<<"result : "<<min_d[start][end]<<'\n';
	return (min_d[start][end]);
}

int		main(void)
{
	int		in[3];
	int		ess_v[2];
	int		ret1, ret2;

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
	cin>>ess_v[0]>>ess_v[1];

	// for(int i=1; i<=n; i++)
	// 	for(int j=1; j<=n; j++)
	// 		min_d[i][j] = INF;
	// cout<<dijkstar(1, ess_v[1])<<'\n';
	// cout<<dijkstar(ess_v[1], ess_v[0])<<'\n';
	// cout<<dijkstar(ess_v[0], n)<<'\n';
	ret1 = dijkstar(1, ess_v[0])+dijkstar(ess_v[0], ess_v[1])+dijkstar(ess_v[1], n);
	ret2 = dijkstar(1, ess_v[1])+dijkstar(ess_v[1], ess_v[0])+dijkstar(ess_v[0], n);
	
	cout<<ret1<<'\n';
	cout<<ret2<<'\n';
	// cout<<min(ret1, ret2)<<'\n';
}