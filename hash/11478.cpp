#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int>	m;
string	str, subStr;
int		len;

int		main(void)
{
	cin>>str;
	len = str.size();
	for(int i=1; i<=len; i++)
		for(int j=0; j<len-i+1; j++)
		{
			subStr = str.substr(j,i);
			m[subStr] = 1;
		}
	cout<<m.size()<<'\n';
}