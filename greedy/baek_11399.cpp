#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	vec;
int		n;

int		greedy(void)
{
	int		ret=0;

	for(int i=1; i<=n; i++)
		ret += vec[i-1]*(n-i+1);
	return (ret);
}



int		main(void)
{
	int		data;

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	cout<<greedy()<<'\n';
}