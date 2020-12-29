#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF	987654321

vector<int>	vec[300002];
bool	flag=false;  // 해가 있는지 없는지 확인하는 플래그
int		n, m, k, x, from, to;
int		dis[300002];

void	dijkstra(int start)
{
	priority_queue< pair<int, int> >	pq;
	int		v, w, next_v, next_w;

	for(int i=1; i<=n; i++)
		dis[i] = INF;
	dis[x] = 0;
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
			next_v = vec[v][i];
			next_w = w+1;
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

	cin>>n>>m>>k>>x;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to;
		vec[from].push_back(to);
	}
	dijkstra(x);
	for(int i=1; i<=n; i++)
		if (dis[i] == k)
		{
			flag = true;
			cout<<i<<'\n';
		}
	if (!flag)
		cout<<-1<<'\n';
}