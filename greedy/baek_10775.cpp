#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX	100002

vector<int>	vec;
int		ap[MAX];
int		g, p;

int		greedy(void)
{
	vector<int>::iterator	iter;
	int 	ret = 0;

	for(int i=0; i<p; i++)
	{
		if (vec.empty())
			break ;
		iter = upper_bound(vec.begin(), vec.end(), ap[i]);
		if (iter == vec.begin())
			break ;
		else
			vec.erase(iter-1);
		ret++;
	}
	return (ret);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>g>>p;
	for(int i=0; i<p; i++)
		cin>>ap[i];
	for(int i=1; i<=g; i++)
		vec.push_back(i);
	cout<<greedy()<<'\n';
}