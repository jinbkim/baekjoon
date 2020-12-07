#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string>	vec;
string	man1[500002], man2[500002];
int		n, m;

void	binary_search(string man)
{
	int		left=0, right=m-1, mid, ans;

	while(left <= right)
	{
		mid = (left+right)/2;
		if (man <= man2[mid])
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	if (man == man2[ans])
		vec.push_back(man);
}

int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>man1[i];
	for(int i=0; i<m; i++)
		cin>>man2[i];
	sort(man1, man1+n);
	sort(man2, man2+m);
	for(int i=0; i<n; i++)
		binary_search(man1[i]);
	cout<<vec.size()<<'\n';
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<'\n';
}