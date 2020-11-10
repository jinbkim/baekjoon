#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string	s, t;
bool	ans=false;

void	greedy(string t)
{
	if (s.size() == t.size())
	{
		if (s == t)
			ans = true;
		return ;
	}
	if (t[t.size()-1] == 'A')
	{
		t.pop_back();
		greedy(t);
		t.push_back('A');
	}
	if (t[0] == 'B')
	{
		reverse(t.begin(), t.end());
		t.pop_back();
		greedy(t);
	}
}



int		main(void)
{
	cin>>s>>t;
	greedy(t);
	if (ans)
		cout<<1<<'\n';
	else
		cout<<0<<'\n';
}