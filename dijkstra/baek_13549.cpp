#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define	INF 987654321

int		dis[200002];
int		from, to;

void	init(void)
{
	for(int i=0; i<200002; i++)  // 넉넉히 범위를 잡아도 시간초과가 안남
		dis[i] = INF;
	dis[from] = 0;
}

void	dijkstra(int start)
{
	priority_queue< pair<int, int> >	pq;
	int		cur, d, next, next_d;

	pq.push(make_pair(0, start));
	while(!pq.empty())
	{
		cur = pq.top().second;
		d = -pq.top().first;
		pq.pop();
		if (cur == to)
			break ;
		if (dis[cur] < d)
			continue ;
		if (d+1 < dis[cur+1])  // x -> x+1
		{
			dis[cur+1] = d+1;
			pq.push(make_pair(-d-1, cur+1));
		}
		if (0<=cur-1 && d+1<dis[cur-1])  // x -> x-1
		{
			dis[cur-1] = d+1;
			pq.push(make_pair(-d-1, cur-1));
		}
		if (cur && cur < to && d < dis[cur*2])  // x -> 2*x
		{
			dis[cur*2] = d;
			pq.push(make_pair(-d, cur*2));
		}
	}
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>from>>to;
	if (to < from)  // 목적지가 출발지보다 더크면
	{
		cout<<from-to<<'\n';  // 계속 한칸뒤로 가는방법만 있음
		return (0);
	}
	init();
	dijkstra(from);
	cout<<dis[to]<<'\n';
}