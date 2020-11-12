#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair< pair<int, int>, int > >	vec;
int		n, day, cost;

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>day>>cost;
		vec.push_back(make_pair(make_pair(day, cost), 0));
	}
	for(int i=0; i<n; i++)
	{
		day = vec[i].first.first;
		if (i+day-1 < n)
			vec[i+day-1].second = max(vec[i+day-1].second, vec[i-1].second+vec[i].first.second);
		if (i>=1)
			vec[i].second = max(vec[i-1].second, vec[i].second);
	}
	cout<<vec[n-1].second<<'\n';
}