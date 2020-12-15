#include <iostream>
#include <vector>
using namespace std;
#define	V	4
#define	INF	987654321

vector< pair<int, pair<int, int> > >	edge;
int		dis[V+1];

void	bellman_ford(int start)
{
	int		from, to, w;

	dis[start] = 0;  // 자기 자신의 최단거리는 0
	for(int i=0; i<=V; i++)  // 정점의 개수만큼 반복
		for(int j=0; j<edge.size(); j++)  // 모든 간선을 탐색
		{
			from = edge[j].second.first;  // 시작 정점
			to = edge[j].second.second;  // 도착 정점
			w = edge[j].first;  // 간선의 가중치
			// 이미 구한 최단거리보다 작은값이면
			if (dis[from]!=INF && dis[from]+w < dis[to])
			{
				dis[to] = dis[from]+w;  // 최단거리 변경
				// 충분히 탐색했음에도 최단거리가 계속 바뀐다는건 음의 순환구조인 경우임
				if (i == V)
				{
					cout<<"negative cycle graph!\n";
					exit(0);
				}
			}
        }
}

int		main(void)
{
	for(int i=1; i<=V; i++)
		dis[i] = INF;  // 최단거리의 초기값은 무한대로 초기화
	// edge.push_back(make_pair(a, make_pair(b, c))) : 정점 b->c 의 간선의 가중치 : a
	// 음의 순환구조인 경우
	edge.push_back(make_pair(3, make_pair(1, 2)));
	edge.push_back(make_pair(2, make_pair(1, 3)));
	edge.push_back(make_pair(5, make_pair(1, 4)));
	edge.push_back(make_pair(3, make_pair(2, 3)));
	edge.push_back(make_pair(-4, make_pair(3, 4)));
	edge.push_back(make_pair(-4, make_pair(4, 2)));

	// 음의 순환구조가 아닌경우
	// edge.push_back(make_pair(3, make_pair(1, 2)));
	// edge.push_back(make_pair(3, make_pair(1, 3)));
	// edge.push_back(make_pair(2, make_pair(2, 3)));
	// edge.push_back(make_pair(-1, make_pair(3, 4)));
	// edge.push_back(make_pair(1, make_pair(4, 2)));

	bellman_ford(1);  // 시작 정점
	for(int i=1; i<=V; i++)
		cout<<dis[i]<<" "<<'\n';
}