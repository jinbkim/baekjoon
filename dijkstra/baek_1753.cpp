#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX	987654321

vector< pair<int, int> >	vec[20002];  // 간선 정보를 담을 벡터
int		dis[20002];  // 최단거리
int		v, e, k, from, to, weight;

void	dijkstra(int start)
{
	priority_queue< pair<int, int> >	pq;  // 간성 정보를 담을 우선순위 큐
	int		v, w, next_v, next_w;

	dis[start] = 0;  // 자기 자신까지의 최단거리는 0
	pq.push(make_pair(0, start));  // 시작지점을 우선순위 큐에 넣음
	while (!pq.empty())  // 우선순위 큐가 비어질때까지 반복
	{
		// 우선순위큐 맨위에있는 정점
		// = 제일 작은 가중치를 가진 정점
		v = pq.top().second;
		// 우선순위큐 맨위에있는 정점의 가중치
		// 제일 작은 가중치
		w = -pq.top().first;
		pq.pop();
		if (dis[v] < w)  // 이미 구한 최단거리보다 가중치가 크면 무시
			continue;
		for(int i=0; i<vec[v].size(); i++)  // 인접 정점을 모두 탐색
		{
			next_v = vec[v][i].second;  // 다음 정점
			next_w = w+vec[v][i].first;  // 다음 정점까지의 거리
			if (next_w < dis[next_v])  // 이미 구한 최단거리보다 더 짧은 거리가 나오면
			{
				dis[next_v] = next_w;  // 최단거리 변경
				// 바뀐 정점을 우선순위큐에 넣음으로써 바뀐정점을 기준으로 다시 탐색
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

	cin>>v>>e>>k;
	for(int i=1; i<=e; i++)
	{
		cin>>from>>to>>weight;
		vec[from].push_back(make_pair(weight, to));
	}
	for(int i=1; i<=v; i++)
		dis[i] = MAX;
	dijkstra(k);
	for(int i=1; i<=v; i++)
	{
		if (dis[i] == MAX)
			cout<<"INF\n";
		else
			cout<<dis[i]<<'\n';
	}
}