#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

map<string, int>::iterator	it;
string	str1, str2;
int	hashArr[32];
int	t, n, idx=0, ret;

int		main(void)
{
	cin>>t;
	for(int i=0; i<t; i++)
	{
		map<string, int>	hashMap;

		cin>>n;
		for(int j=0; j<n; j++)
		{
			cin>>str1>>str2;
			if (hashMap.find(str2) == hashMap.end())
				hashMap[str2] = 1;
			else
				hashMap[str2]++;
		}
		ret = 1;
		for(it=hashMap.begin(); it!=hashMap.end(); it++)
			ret *= (it->second+1);
		cout<<ret-1<<'\n';
	}
}