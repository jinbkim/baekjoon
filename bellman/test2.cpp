#include <iostream>
#include <vector>
#include <cstring>
using namespace	std;

#define MAX	102
#define INF 987654321
#define GEE -99

vector< pair<int, int> >	vec[MAX];
long long	min_d[MAX];
bool	visted[MAX];
int		n, m, s, e, from, to, cost, ret;
int		city[MAX];

void	dfs(int idx)
{
	if (visted[idx])
		return ;
	visted[idx] = true;
	for(int i=0; i<vec[idx].size(); i++)
		dfs(vec[idx][i].first);
}

bool	check_gg(void)
{
	memset(visted, 0, sizeof(visted));
	dfs(s);
	if (visted[e])
		return (false);
	else
		return (true);
}

void	init(void)
{
	for(int i=1; i<=n; i++)
		min_d[i] = INF;
	min_d[s] = -city[s];
}

int		bellman(void)
{
	if (s == e)
		return (city[s]);
	for(int i=0; i<=n+7564321; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<vec[j].size(); k++)
			{
				from = j;
				to = vec[j][k].first;
				cost = vec[j][k].second-city[to];
				if (min_d[from] == INF)
					continue ;
				// cout<<"from : "<<from<<", to : "<<to<<", cost : "<<cost<<'\n';
				// cout<<"min_d[from] : "<<min_d[from]<<", min_d[to] : "<<min_d[to]<<'\n';	
				if (min_d[from]+cost < min_d[to])
				{
					min_d[to] = min_d[from]+cost;
					// cout<<"--from : "<<from<<", to : "<<to<<", cost : "<<cost<<'\n';
					// cout<<"--min_d[from] : "<<min_d[from]<<", min_d[to] : "<<min_d[to]<<'\n';
					if (n < i && to == e)
						return (GEE);
				}
			}
	return (-min_d[e]);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>s>>e>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
	}
	for(int i=0; i<n; i++)
		cin>>city[i];
	if (check_gg())
	{
		cout<<"gg\n";
		return (0);
	}
	init();
	ret = bellman();
	if (ret == GEE)
		cout<<"Gee\n";
	else
		cout<<ret<<'\n';
}