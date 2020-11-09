#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool 	comp(char x, char y)
{
	return (x>y);
}



int		main(void)
{
	string	str;
	int		sum;

	cin>>str;
	sort(str.begin(), str.end(), comp);
	for(int i=0; i<str.size(); i++)
		sum += str[i]-'0';
	if (str[str.size()-1] == '0' && sum%3==0)
		cout<<str<<'\n';
	else
		cout<<-1<<'\n';
}