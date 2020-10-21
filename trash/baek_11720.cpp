#include <iostream>

using namespace std;

string	str;
int		n, ret = 0;

int	main(void)
{
	cin>>n>>str;

	for(int i=0; i<n; i++)
		ret += str[i] - '0';
	cout<<ret<<'\n';
}