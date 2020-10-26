#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector< pair<int, int> >	vec[502];
long long	min_d[502];
int		INF = 2147483647;
int		n, m, from, to, cost;



void	bellman(void)
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
			{
				cout<<-1<<'\n';
				return ;
			}
		}
	}
	for(int i=2; i<=n; i++)
	{
		if (min_d[i] == INF)
			cout<<-1<<'\n';
		else
			cout<<min_d[i]<<'\n';
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
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
	}
	for(int i=1; i<=n; i++)
		min_d[i] = INF;
	bellman();
}