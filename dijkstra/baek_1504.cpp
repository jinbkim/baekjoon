#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define	INF	987654321

vector< pair<int, int> >	vec[802];
int		dis[802];
int		path1[3];  // 1->v1->v2->n
int		path2[3];  // 1->v2->v1->n
int		n, e, from, to, w, v1, v2, ret;

void	dijkstra(int start)
{
	priority_queue< pair<int, int> >	pq;
	int		v, w, next_v, next_w;

	for(int i=1; i<=n; i++)
		dis[i] = INF;
	dis[start] = 0;
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

	cin>>n>>e;
	for(int i=0; i<e; i++)  // 방향이 없는 간선
	{
		cin>>from>>to>>w;
		vec[from].push_back(make_pair(w, to));
		vec[to].push_back(make_pair(w, from));
	}
	cin>>v1>>v2;
	dijkstra(1);  // 정점 1에서 t까지의 최단거리가 dis[t]에 저장됨
	path1[0] = dis[v1];  // 1->v1
	path2[0] = dis[v2];  // 1->v2
	dijkstra(v1);  // 정점 v1에서 t까지의 최단거리가 dis[t]에 저장됨
	path1[1] = dis[v2];  // v1->v2
	path2[2] = dis[n];  // v1->n
	dijkstra(v2);  // 정점 v2에서 t까지의 최단거리가 dis[t]에 저장됨
	path2[1] = dis[v1];  // v2->v1
	path1[2] = dis[n];  // v2->n
	// 1->v1->v2->n vs 1->v2->v1->n
	ret = min(path1[0]+path1[1]+path1[2], path2[0]+path2[1]+path2[2]);
	if ((path1[0]==INF||path1[1]==INF||path1[2]==INF) && (path2[0]==INF||path2[1]==INF||path2[2]==INF))
		ret = -1;
	cout<<ret<<'\n';
}