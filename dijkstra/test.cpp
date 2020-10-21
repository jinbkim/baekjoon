#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
#define INF	999

vector< pair<int, int> >	pair_v[7];
int	dis[7];
int	n = 6;

void	dijkstra(int start)
{
	priority_queue< pair<int, int> >	pq;

	dis[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int	vtx, distance;

		distance = -pq.top().first;
		vtx = pq.top().second;
		pq.pop();
		if (dis[vtx] < distance)
			continue ;
		for (int i=0; i<pair_v[vtx].size(); i++)
		{
			int next_vtx, next_distance;

			next_distance = pair_v[vtx][i].second + distance;
			next_vtx = pair_v[vtx][i].first;
			if (next_distance < dis[next_vtx])
			{
				dis[next_vtx] = next_distance;
				pq.push(make_pair(-next_distance, next_vtx));
			}
		}
	}
}



int		main(void)
{
	for(int i=1; i<=n; i++)
		dis[i] = INF;

	pair_v[1].push_back(make_pair(2, 2));
	pair_v[1].push_back(make_pair(3, 5));
	pair_v[1].push_back(make_pair(4, 1));

	pair_v[2].push_back(make_pair(1, 2));
	pair_v[2].push_back(make_pair(3, 3));
	pair_v[2].push_back(make_pair(4, 2));

	pair_v[3].push_back(make_pair(1, 5));
	pair_v[3].push_back(make_pair(2, 3));
	pair_v[3].push_back(make_pair(4, 3));
	pair_v[3].push_back(make_pair(5, 1));
	pair_v[3].push_back(make_pair(6, 5));

	pair_v[4].push_back(make_pair(1, 1));
	pair_v[4].push_back(make_pair(2, 2));
	pair_v[4].push_back(make_pair(3, 3));
	pair_v[4].push_back(make_pair(5, 1));

	pair_v[5].push_back(make_pair(3, 1));
	pair_v[5].push_back(make_pair(4, 1));
	pair_v[5].push_back(make_pair(6, 2));

	pair_v[6].push_back(make_pair(3, 5));
	pair_v[6].push_back(make_pair(5, 2));

	dijkstra(1);

	for(int i=1; i<=n; i++)
		cout<<dis[i]<<" ";
}