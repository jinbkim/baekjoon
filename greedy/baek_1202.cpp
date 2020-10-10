#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;
vector<vector<int>>	vv;
multiset<int>	bag;
multiset<int>::iterator iter;

int	n, k, c, ret;

void	put_in(void)
{
	multiset<int>::iterator iter;

	iter = bag.lower_bound(vv.back()[1]);

	if (iter != bag.end())
	{
		bag.erase(iter);
		ret += vv.back()[0];
		c++;
	}

	vv.pop_back();
}

int		main(void)
{
	cin>>n>>k;
	for(int i=0; i<n; i++)
	{
		vector<int>	v(2);
		cin>>v[1]>>v[0];
		vv.push_back(v);
	}
	for(int i=0; i<k; i++)
	{
		int temp;

		cin>>temp;
		bag.insert(temp);
	}
	sort(vv.begin(), vv.end());

	c = 0;
	ret = 0;
	for(int i=n-1; 0<=i; i--)
	{
		// put_in();
		vector <int>v = vv[i];
		iter = bag.lower_bound(v[1]);
		if (iter != bag.end())
		{
			bag.erase(iter);
			ret += v[0];
			c++;
		}
		if (c == k)
			break ;
	}
	cout<<ret<<endl;

}