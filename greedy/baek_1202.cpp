#include <iostream>
#include <set>
using namespace std;

multiset< pair<int, int> >	jewelry;
multiset< pair<int, int> >::iterator	j_iter;
multiset<int>	bag;
multiset<int>::iterator	b_iter;

int		n, k, weight, price;

long long	greedy(void)
{
	long long	ret = 0;

	j_iter = jewelry.end();
	while (true)
	{
		j_iter--;
		if (bag.empty())
			break ;
		b_iter = bag.lower_bound(j_iter->second);
		if (b_iter == bag.end())
		{
			if (j_iter == jewelry.begin())
				break ;
			else
				continue ;
		}
		ret += j_iter->first;
		bag.erase(b_iter);
		if (j_iter == jewelry.begin())
			break ;
	}
	return (ret);
}



int			main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=0; i<n; i++)
	{
		cin>>weight>>price;
		jewelry.insert(make_pair(price, weight));
	}
	for(int i=0; i<k; i++)
	{
		cin>>weight;
		bag.insert(weight);
	}
	cout<<greedy()<<'\n';
}