#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

#define	INF		987654321
#define	MAX		102

vector< pair<int, int> >	vec[MAX];
long long	min_d[MAX];
long long	city[MAX];
bool	visted[MAX];
int		n, m, start_c, end_c, from, to, ret, cost;
int		bellman(int start_c, int end_c)
{
	if (start_c == end_c)
		return (city[start_c]);
	min_d[start_c] = -city[start_c];
	for(int i=0; i<n+2000001; i++)
		for(int j=0; j<n; j++)
			for(long unsigned int k=0; k<vec[j].size(); k++)
			{
				from = j;
				to = vec[j][k].first;
				cost = vec[j][k].second-city[to];
				if (min_d[from] == INF)
					continue ;
				if (min_d[from]+cost < min_d[to])
				{
					min_d[to] = min_d[from] + cost;
					// cout<<"from : "<<from<<", to : "<<to<<", cost : "<<cost<<'\n';
					// cout<<"min_d[from] : "<<min_d[from]<<", min_d[to] : "<<min_d[to]<<'\n';
					if (i >= n && to == end_c)
						return (0); 
				}
			}
	return (-min_d[end_c]);
}

void	dfs(int n)
{
	if (visted[n])
		return ;
	visted[n] = true;
	for(long unsigned int i=0; i<vec[n].size(); i++)
		dfs(vec[n][i].first);
}

bool	check_gg(void)
{
	memset(visted, 0, sizeof(visted));
	dfs(start_c);
	if (!visted[end_c])
		return (true);
	else
		return (false);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>start_c>>end_c>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
	}
	for(int i=0; i<n; i++)
		cin>>city[i];
	for(int i=0; i<n; i++)
		min_d[i] = INF;
	if (check_gg())
	{
		cout<<"gg\n";
		return (0);
	}
	ret = bellman(start_c, end_c);
	if (ret)
		cout<<ret<<'\n';
	else
		cout<<"Gee\n";
}