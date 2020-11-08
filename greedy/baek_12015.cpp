#include <iostream>
#include <vector>
using namespace std;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>		ans;
	vector<int>::iterator	iter;
	int		data, n;

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		iter = lower_bound(ans.begin(), ans.end(), data);
		if (iter == ans.end())
			ans.push_back(data);
		else
			*iter = data;
	}
	cout<<ans.size()<<'\n';
}