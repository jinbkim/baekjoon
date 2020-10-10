#include <iostream>
#include <stack>

using namespace std;

stack<int>	s;
int		n, oper;



void	push(void)
{
	cin>>oper;
	s.push(oper);
}

void	pop(void)
{
	if (s.empty())
		cout<<-1<<endl;
	else
	{
		cout<<s.top()<<endl;
		s.pop();
	}
}

void	size(void)
{
	cout<<s.size()<<endl;
}

void	empty(void)
{
	if (s.empty())
		cout<<1<<endl;
	else
		cout<<0<<endl;
}

void	top(void)
{
	if (s.empty())
		cout<<-1<<endl;
	else
		cout<<s.top()<<endl;
}



int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		string	cmd;
		cin>>cmd;
		if (!cmd.compare("push"))
			push();
		else if (!cmd.compare("pop"))
			pop();
		else if (!cmd.compare("size"))
			size();
		else if (!cmd.compare("empty"))
			empty();
		else if (!cmd.compare("top"))
			top();
	}
}