#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector< pair<int, int> > 	vec1[1002];
vector< pair<int, int> > 	vec2[1002];
int		dis1[1002], dis2[1002];
int		n, m, x, from, to, w, ret;

void	init(void)
{
	ret = 0;
	for(int i=1; i<=n; i++)
	{
		dis1[i] = 987654321;
		dis2[i] = 987654321;
	}
}

void	dijkstra1(int start)
{
	priority_queue< pair<int, int> >	pq;
	int		v, w, next_v, next_w;

	dis1[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		v = pq.top().second;
		w = -pq.top().first;
		pq.pop();
		if (dis1[v] < w)
			continue ;
		for(int i=0; i<vec1[v].size(); i++)
		{
			next_v = vec1[v][i].second;
			next_w = vec1[v][i].first+w;
			if (next_w < dis1[next_v])
			{
				dis1[next_v] = next_w;
				pq.push(make_pair(-next_w, next_v));
			}
		}
	}
}


void	dijkstra2(int start)
{
	priority_queue< pair<int, int> >	pq;
	int		v, w, next_v, next_w;

	dis2[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		v = pq.top().second;
		w = -pq.top().first;
		pq.pop();
		if (dis1[v] < w)
			continue ;
		for(int i=0; i<vec2[v].size(); i++)
		{
			next_v = vec2[v][i].second;
			next_w = vec2[v][i].first+w;
			if (next_w < dis2[next_v])
			{
				dis2[next_v] = next_w;
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

	cin>>n>>m>>x;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>w;
		vec1[from].push_back(make_pair(w, to));
		vec2[to].push_back(make_pair(w, from));
	}
	init();
	dijkstra1(x);
	dijkstra2(x);
	for(int i=1; i<=n; i++)
	{
		cout<<"dis1[i]+dis2[i] : "<<dis1[i]+dis2[i]<<'\n';
		ret = max(ret, (dis1[i]+dis2[i]));
	}
	cout<<ret<<'\n';
}