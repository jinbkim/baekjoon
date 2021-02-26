#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>				lis;
vector<int>::iterator	it;
int	arr[40002];
int	n;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++)
	{
		it = lower_bound(lis.begin(), lis.end(), arr[i]);
		if (it == lis.end())
			lis.push_back(arr[i]);
		else
			*it = arr[i];
	}
	cout<<lis.size();
}