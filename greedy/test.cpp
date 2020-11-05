#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> >	jewerly;
vector< pair <int, bool> >	bag;
vector< pair<int, bool> >::iterator	iter;
int		n, k, weight, price;

int		greedy(void)
{
	int		ret=0, cnt=0;
	
	for(int i=n-1; 0<=i; i--)
	{
		iter = lower_bound(bag.begin(), bag.end(), jewerly[i].second);
		if (iter == bag.end() || iter.second == true)
			continue ;
		cnt++;
		if (cnt == k)
			break ;
		// for(int j=0; j<k; j++)
		// {
		// 	if (bag[j].second)
		// 		continue ;
		// 	if (jewerly[i].second <= bag[j].first)
		// 	{
		// 		ret += jewerly[i].first;
		// 		bag[j].second = true;
		// 		cnt++;
		// 		break ;
		// 	}
		// }
		// if (cnt == k)
		// 	break ;
	}
	return (ret);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>k;
	for(int i=0; i<n; i++)
	{
		cin>>weight>>price;
		jewerly.push_back(make_pair(price, weight));
	}
	sort(jewerly.begin(), jewerly.end());
	for(int i=0; i<k; i++)
	{
		cin>>weight;
		bag.push_back(make_pair(weight, false));
	}
	sort(bag.begin(), bag.end());
	cout<<greedy()<<'\n';
}