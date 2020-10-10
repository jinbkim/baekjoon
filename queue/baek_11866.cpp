#include <iostream>
#include <queue>

using namespace	std;

queue<int>	q;
int		n, k, q_data;

int		main(void)
{
	cin>>n>>k;
	for(int i=0; i<n; i++)
		q.push(i+1);
	cout<<'<';
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<k; j++)
		{
			if (j == k-1)
			{
				cout<<q.front();
				if (i != n-1)
					cout<<", ";
			}
			else
				q.push(q.front());
			q.pop();
		}
	}
	cout<<">\n";
}