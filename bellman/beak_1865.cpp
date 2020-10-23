#include <iostream>
#include <vector>
#include <utility>

using namespace std;
#define	MAX	502

vector< pair<int, int>	>	vec[MAX];
int		min_d[MAX];
int		INF = 2147483647;
int		tc, n, m, w, to, from, cost;

bool	bellman(void)
{
	min_d[1] = 0;
	for(int i=1; i<=n-1; i++)
		for(int j=1; j<=n; j++)
			for(int k=0; k<vec[j].size(); k++)
			{
				from = j;
				to = vec[j][k].first;
				cost = vec[j][k].second;
				if (min_d[from] == INF)
					continue ;
				if (min_d[from]+cost < min_d[to])
					min_d[to] = min_d[from]+cost;
			}
	for(int j=1; j<=n; j++)
	{
		for(int k=0; k<vec[j].size(); k++)
		{
			from = j;
			to = vec[j][k].first;
			cost = vec[j][k].second;
			if (min_d[from] == INF)
				continue ;
			if (min_d[from]+cost < min_d[to])
				return (0);
		}
	}

}

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>tc;
	for(int i=0; i<tc; i++)
	{
		cin>>n>>m>>w;
		for(int i=1; i<=n; i++)
			min_d[i] = INF;
		for(int i=0; i<m; i++)
		{
			cin>>to>>from>>cost;
			vec[to].push_back(make_pair(from, cost));
		}
		for(int i=0; i<w; i++)
		{
			cin>>to>>from>>cost;
			vec[to].push_back(make_pair(from, -cost));
		}
		bellman();
	}
}