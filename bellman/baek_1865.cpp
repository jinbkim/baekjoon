#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
#define	MAX	502

vector< pair<int, int>	>	vec[MAX];
long long	INF = 2147483647;
long long	min_d[MAX];
int		tc, n, m, w, to, from, cost, ret;

void	init(void)
{
	for(int i=1; i<=n; i++)
	{
		min_d[i] = INF;
		vec[i].clear();
	}
	min_d[1] = 0;
}

bool	bellman(void)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=0; k<vec[j].size(); k++)
			{
				from = j;
				to = vec[j][k].first;
				cost = vec[j][k].second;
				if (min_d[from]+cost < min_d[to])
				{
					min_d[to] = min_d[from]+cost;
					if (i == n)
						return (true); 
				}
			}
	return (false);
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
		init();
		for(int j=0; j<m; j++)
		{
			cin>>from>>to>>cost;
			vec[from].push_back(make_pair(to, cost));
			vec[to].push_back(make_pair(from, cost));
		}
		for(int j=0; j<w; j++)
		{
			cin>>from>>to>>cost;
			vec[from].push_back(make_pair(to, -cost));
		}
		ret = bellman();
		if (ret)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}