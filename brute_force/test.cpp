#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool	visited[102];
bool	flag=false;
// int		ans[102];
int		n;
pair<long long, int>	ans[102];
vector< pair<long long, int> >	vec;

void	init(void)
{
	memset(visited, 0, sizeof(visited));
}

void	solve(int idx)
{
	// cout<<"idx : "<<idx<<'\n';
	if (flag)
		return ;
	if (idx == n)
	{
		flag = true;
		return ;
	}
	for(int i=0; i<n; i++)
	{
		// cout<<"i : "<<i<<'\n';
		if (flag)
			return ;
		if (!idx || (!visited[i] && vec[i].second <= ans[idx-1].second && ((ans[idx-1].first%3==0 && ans[idx-1].first/3==vec[i].first) || ans[idx-1].first*2==vec[i].first)))
		{
			visited[i] = true;
			ans[idx].first = vec[i].first;
			ans[idx].second = vec[i].second;
			// cout<<"idx : "<<idx<<", arr[idx] : "<<ans[idx].first<<'\n';
			// ans[idx].first = vec[i].first;
			solve(idx+1);
			visited[i] = false;
		}
	}
}

int		main(void)
{
	long long	a, b, c;
	init();
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a;
		b = a;
		c = 0;
		while (b%3 == 0)
		{
			b /= 3;
			c++;
		}
		vec.push_back(make_pair(a, c));
	}
	solve(0);
	for(int i=0; i<n; i++)
		cout<<ans[i].first<<" "; 
}