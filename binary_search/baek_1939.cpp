#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define	MAX	100002

vector< pair<int, int> >	vec[MAX];
int 	visited[MAX];
int		n, m, from, to, cost, range;

void	init(void)
{
	range = 0;
}

void	dfs(int idx, int cost)
{
	if (visited[idx])
		return ;
	visited[idx] = true;
	for(int i=0; i<vec[idx].size(); i++)
		if (cost <= vec[idx][i].second)
			dfs(vec[idx][i].first, cost);
}

bool	is_possible(int cost)
{
	memset(visited, 0, sizeof(visited));
	dfs(from ,cost);
	if (visited[to])
		return (true);
	else
		return (false);
}

int		bs(int left, int right)
{
	int		mid, ans;
	
	while(left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			ans = mid;
			left = mid+1;
		}
		else
			right = mid-1;
	}
	return (ans);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);

	init();
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
		vec[to].push_back(make_pair(from, cost));
		if (range < cost)
			range = cost;
	}
	cin>>from>>to;
	cout<<bs(1, range)<<'\n';
}