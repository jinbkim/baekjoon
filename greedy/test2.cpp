#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, bool> >	bag;
vector< pair<int, bool> >	b;

int		main(void)
{
	bag.push_back(make_pair(30, false));
	cout<<bag[0].first<<", "<<bag[0].second<<'\n';

	// cout<<bag[0].first()<<", "<<bag[0].end()<<'\n';
}