#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector< pair<int, int> >	vec[22];
int		dp[22][302];
int		n, m, l, k;

void	init(void)
{
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<m; i++)
		vec[i].push_back(make_pair(0, 0));
}

int		solve(int idx, int sum, int ans)
{
	int		ret=0;
	for(int i=0; i<n; i++)
		ret = max(ret, solve(idx+1, sum+(vec[i].begin()), ans+(vec[i].second())));
}

int		main(void)
{
	cin>>n>>m;
	init();
	for(int i=0; i<n; i++)
	{
		cin>>l;
		for(int j=0; j<m; j++)
		{
			cin>>k;
			vec[j].push_back(make_pair(l, k));
		}
	}
	cout<<solve(0, 0, 0)<<'\n';
}