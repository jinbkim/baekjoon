#include <iostream>
#include <stack>

using namespace std;

stack<int>	s;



int		main(void)
{
	int	k, n;

	cin>>k;
	for(int i=0; i<k; i++)
	{
		cin>>n;
		if (!n)
		{
			if (!s.empty())
				s.pop();
		}
		else
			s.push(n);
	}

	int	ret = 0;
	while (!s.empty())
	{
		ret += s.top();
		s.pop();
	}
	cout<<ret<<endl;
}
