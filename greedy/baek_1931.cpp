#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define	MAX 2147483648

vector< pair<long long, long long> >	vec;
long long	n, from, to;

long long	greedy(void)
{
	long long	cnt=0, start=0;

	for(int i=0; i<n; i++)
	{
		if (start <= vec[i].second)
		{
			cnt++;
			start = vec[i].first;
		}
	}
	return (cnt);
}



int			main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>from>>to;
		vec.push_back(make_pair(to, from));
	}
	sort(vec.begin(), vec.end());
	cout<<greedy()<<'\n';
}