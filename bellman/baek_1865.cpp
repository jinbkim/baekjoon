#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define	INF	987654321
#define	MAX	502

typedef struct	s_info
{
	int		s;
	int		e;
	int		w;
}				t_info;

vector<t_info>	vec;
t_info	info;
long long	min_d[MAX];
int		tc, n, m, w, from, to, cost;

void	init(void)
{
	vec.clear();
	for(int i=1; i<=n; i++)
		min_d[i] = INF;
	min_d[1] = 0;
}

bool	bellman(void)
{
	for(int i=1; i<=n*2; i++)
		for(int j=0; j<vec.size(); j++)
		{
			from = vec[j].s;
			to = vec[j].e;
			cost = vec[j].w;
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

	cin>>tc;
	for(int i=0; i<tc; i++)
	{
		init();
		cin>>n>>m>>w;
		for(int j=0; j<m; j++)
		{
			cin>>info.s>>info.e>>info.w;
			vec.push_back(info);
			swap(info.s, info.e);
			vec.push_back(info);
		}
		for(int j=0; j<w; j++)
		{
			cin>>info.s>>info.e>>info.w;
			info.w *= -1;
			vec.push_back(info);
		}
		if (bellman())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}