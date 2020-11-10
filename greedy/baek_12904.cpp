#include <iostream>
#include <string>
using namespace std;

void	reverse_word(string &t)
{
	char	temp;
	for(int i=0; i<t.size()/2; i++)
	{
		temp = t[i];
		t[i] = t[t.size()-1-i];
		t[t.size()-1-i] = temp;
	}
}



int		main(void)
{
	string	s, t;
	
	cin>>s>>t;
	while(s.size() != t.size())
	{
		if (t[t.size()-1] == 'A')
			t.pop_back();
		else
		{
			t.pop_back();
			reverse_word(t);
		}
	}
	if (s==t)
		cout<<1<<'\n';
	else
		cout<<0<<'\n';	
}