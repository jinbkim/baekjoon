#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> >	vec;
int		visted[102];
int		n, k, w, v, ret;

void	solve(int a, int b)
{
	if (k < a)
		return ;
	for(int i=0; i<vec.size(); i++)
	{
		solve(a, vec[i])
	}
}

int		main(void)
{
	memset(visted, 0, sizeof(visted));
	cin>>n>>k;
	for(int i=0; i<n; i++)
	{
		cin>>w>>k;
		vec.push_back(make_pair(w, k));
	}
	sort(vec.begin(), vec.end());
	solve(0, 0);
	cout<<ret<<'\n';
}