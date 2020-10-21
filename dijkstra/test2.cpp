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
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int current, distance;

		current = pq.top().first;
		distance = -pq.top().second;
		// distance = pq.top().second;

		// cout<<"current : "<<current<<", distance : "<<distance<<'\n';
		pq.pop();
		if (dis[current] < distance)
			continue ;
		cout<<"-------\n";
		for(int i=0; i<pair_v[current].size(); i++)
		{
			int next, next_d;

			next = pair_v[current][i].first;
			next_d = distance + pair_v[current][i].second;
			if (next_d < dis[next])
			{
				cout<<"current : "<<current<<", next_d : "<<next_d<<", next : "<<next<<", dis : "<<dis[next]<<'\n';

				dis[next] = next_d;
				pq.push(make_pair(next, -next_d));
				// pq.push(make_pair(next, next_d));

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