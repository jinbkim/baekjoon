#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define INF	987654321

vector< pair<long long, pair<long long, long long> > >	edge;
bool		visit[102];
long long	dis[102], before[102], after[102];
long long	n, m, from, to, weight;

void	bellman_ford(void)
{
	memset(visit, 0, sizeof(visit));
	for(int i=2; i<=n; i++)
		dis[i] = -INF;
	dis[1] = 0;
	visit[n] = true;
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<edge.size(); j++)
		{
			from = edge[j].second.first;
			to = edge[j].second.second;
			weight = edge[j].first;
			if (visit[to])
				visit[from] = true;
			if (dis[from]!=-INF && dis[to]<dis[from]+weight)
			{
				after[to] = from;
				dis[to] = dis[from]+weight;
				edge[j].first = 0;
				// cout<<"from : "<<from<<", dis[from] : "<<dis[from]<<", to : "<<to<<", dis[to]: "<<dis[to]<<", after[to] : "<<after[to]<<'\n';
				if(i == n && visit[to])
				{
					cout<<-1<<'\n';
					exit(0);
				}
			}
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>weight;
		edge.push_back(make_pair(weight, make_pair(from, to)));
	}
	bellman_ford();
	if (dis[n] == -INF)
		cout<<-1<<'\n';
	else
	{
		for(int i=2; i<=n; i++)
			before[after[i]] = i;
		from = 1;
		cout<<1<<' ';
		while(1)
		{
			to = before[from];
			cout<<to<<' ';
			if (to == n)
				break ;
			from = to;
		}
	}
}