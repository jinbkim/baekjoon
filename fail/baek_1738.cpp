#include <iostream>
#include <vector>

using namespace std;
#define	MAX	102
#define INF -2147483647

vector< pair<int, int> >	vec[MAX];
vector<int>	path;
long long	min_d[MAX];
int		pre[MAX];
int		n, m, from, to, cost, ret, idx;

void	init(void)
{
	for(int i=1; i<=n; i++)
		min_d[i] = INF;
}

bool	bellman(void)
{
	for (int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=0; k<vec[j].size(); k++)
			{
				from = j;
				to = vec[j][k].first;
				cost = vec[j][k].second;
				if (min_d[to] < min_d[from] + cost)
				{
					pre[to] = from;
					min_d[to] = min_d[from] + cost;
					if (i == n && to == n)
						return (false); 
				}
			}
	return (true);
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
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
	}
	ret = bellman();
	if (ret)
	{
		idx = n;
		while (1)
		{
			path.push_back(idx);
			if (idx == 1)
				break ;
			else
				idx = pre[idx];
		}
		for(int i=path.size()-1; 0<=i; i--)
			cout<<path[i]<<" ";
	}
	else
		cout<<"-1\n";
}