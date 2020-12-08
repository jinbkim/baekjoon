#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string>	vec[50];
string	str;
int		n;

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>str;
		vec[str.size()].push_back(str);
	}
	for(int i=1; i<=50; i++)
		sort(vec[i].begin(), vec[i].end());
	for(int i=1; i<=50; i++)
	{
		str.clear();
		for(int j=0; j<vec[i].size(); j++)
		{
			if (str == vec[i][j])
				continue ;
			str = vec[i][j];
			cout<<vec[i][j]<<'\n';
		}
	}
}