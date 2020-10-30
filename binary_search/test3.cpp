#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define	MAX	100002	

vector < pair<int, int> >	vec[MAX];
int		visted[MAX];
int		n, m, from, to, cost, max_range = 0;

void	dfs(int from, int val)
{
	if (visted[from])
		return ;
	visted[from] = true;
	for(int i=0; i<vec[from].size(); i++)
		if (val <= vec[from][i].second)
			dfs(vec[from][i].first, val);
}

int		is_possible(int val)
{
	memset(visted, 0, sizeof(visted));
	dfs(from, val);
	if (visted[to])
		return (true);
	else
		return (false);
}

int		bs(int left, int right)
{
	int		mid, ans;

	while (left <= right)
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

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>cost;
		vec[from].push_back(make_pair(to, cost));
		vec[to].push_back(make_pair(from, cost));
		if (max_range < cost)
			max_range = cost;
	}
	cin>>from>>to;
	cout<<bs(1, max_range)<<'\n';
}