#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int>			hashMap;
map<string, int>::iterator	it;
string	str1, str2;
int		n;

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>str1>>str2;
		if (str2 == "enter")
			hashMap[str1] = 1;
		else if (str2 == "leave")
			hashMap[str1] = 0;
	}
	it=hashMap.end();
	while(1)
	{
		it--;
		if (it->second)
			cout<<it->first<<'\n';
		if (it == hashMap.begin())
			break ;
	}
}