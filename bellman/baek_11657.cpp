#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define INF	987654321
#define	MAX	502

typedef	struct 	s_info
{
	int		s;
	int		e;
	int		w;
}				t_info;

vector<t_info>	vec;
t_info	info;
long long	min_d[MAX];
int		n, m, from, to, cost;

void	init(void)
{
	for(int i=2; i<=n; i++)
		min_d[i] = INF;
}

bool	bellman(void)
{
	for(int i=0; i<=n*2; i++)
		for(int j=0; j<vec.size(); j++)
		{
			from = vec[j].s;
			to = vec[j].e;
			cost = vec[j].w;
			if (min_d[from] == INF)
				continue ;
			if (min_d[from]+cost < min_d[to])
			{
				min_d[to] = min_d[from]+cost;
				if (n < i)
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

	cin>>n>>m;
	init();
	for(int i=0; i<m; i++)
	{
		cin>>info.s>>info.e>>info.w;
		vec.push_back(info);
	}
	if (bellman())
	{
		cout<<"-1\n";
		return (0);
	}
	for(int i=2; i<=n; i++)
	{
		if (min_d[i] == INF)
			cout<<"-1\n";
		else
			cout<<min_d[i]<<'\n';
	}
}