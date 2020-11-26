#include <iostream>
using namespace std;

int		main(void)
{
	char	str[52];
	int		n, s=0, l=0;

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>str[i];
		if (str[i] == 'S')
			s++;
		else if (str[i] == 'L')
			l++;
	}
	if (!l)
		cout<<s<<'\n';
	else
		cout<<s+(l/2)+1<<'\n';
}