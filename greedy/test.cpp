#include <iostream>
#include <set>
using namespace std;

multiset< pair<int , int> >	day_ms;
multiset< pair<int , int> >::iterator	iter;
multiset<int>	ans_ms;
multiset<int>::iterator	iter2;

int		n, price, day;

int		greedy(void)
{
	int		ret=0;

	for(iter=day_ms.begin(); iter!=day_ms.end(); iter++)
	{
		ret += iter->second;
		ans_ms.insert(iter->second);
		if (iter->first < ans_ms.size())
		{
			ret -= *ans_ms.begin();
			ans_ms.erase(ans_ms.begin());
		}
	}
	return (ret);
}



int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>price>>day;
		day_ms.insert(make_pair(day, price));
	}
	cout<<greedy()<<'\n';
}