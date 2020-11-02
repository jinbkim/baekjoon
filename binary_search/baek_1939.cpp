#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 10002

vector< pair<int, int> >	vec[MAX];
bool	visited[MAX];
int		n, m, from, to, cost;

void	dfs(int edge, int val)
{
	if (visited[edge])
		return ;
	visited[edge] = true;
	for(int i=0; i<vec[edge].size(); i++)
		if (val <= vec[edge][i].second)
			dfs(vec[edge][i].first, val);
}

bool 	is_possible(int val)
{
	memset(visited, 0, sizeof(visited));
	dfs(from, val);
	if (visited[to])
		return (true);
	else
		return (false);
}

int		bs(long long left, long long right)
{
	long long	mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			left = mid+1;
			ans = mid;
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
	}
	cin>>from>>cost;
	cout<<bs(1, 1000000000)<<'\n';
}