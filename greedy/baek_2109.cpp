#include <iostream>
#include <set>
#include <queue>
using namespace std;

multiset< pair<int, int> >	day_ms;
multiset< pair<int, int> >::iterator	iter;
priority_queue<int, vector<int>, greater<int> >	ans_pq;
int		n, price, day;

int		greedy(void)
{
	int		ret=0;

	for(iter=day_ms.begin(); iter!=day_ms.end(); iter++)
	{
		ret += iter->second;
		ans_pq.push(iter->second);
		if (iter->first < ans_pq.size())
		{
			ret -= ans_pq.top();
			ans_pq.pop();
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