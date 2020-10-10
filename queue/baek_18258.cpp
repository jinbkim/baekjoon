#include <iostream>
#include <queue>


using namespace std;

queue<int>	q;
int		n, oper;



void	push(void)
{
	cin>>oper;
	q.push(oper);
}

void	pop(void)
{
	if (q.empty())
		cout<<"-1\n";
	else
	{
		cout<<q.front()<<'\n';
		q.pop();
	}
}

void	empty(void)
{
	if (q.empty())
		cout<<"1\n";
	else
		cout<<"0\n";
}

void	front(void)
{
	if (q.empty())
		cout<<"-1\n";
	else
		cout<<q.front()<<'\n';
}

void	back(void)
{
	if (q.empty())
		cout<<"-1\n";
	else
		cout<<q.back()<<'\n';
}

int		main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		string cmd;

		cin>>cmd;
		if (!cmd.compare("push"))
			push();
		else if (!cmd.compare("pop"))
			pop();
		else if (!cmd.compare("size"))
			cout<<q.size()<<'\n';
		else if (!cmd.compare("empty"))
			empty();
		else if (!cmd.compare("front"))
			front();
		else if (!cmd.compare("back"))
			back();
	}
}