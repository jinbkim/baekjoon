#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool	check_word(string s)
{
	bool	visited[200];
	int		i = -1;

	memset(visited, false, sizeof(visited));
	while(s[++i])
	{
		if (visited[s[i]] && (s[i-1] != s[i]))
			return (false);
		else
			visited[s[i]] = true;
	}
	return (true);
}

int		main(void)
{
	string	str;
	int		n, ret=0;

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>str;
		if (check_word(str))
			ret++;
	}
	cout<<ret<<'\n';
}