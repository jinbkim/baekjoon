#include <iostream>
#include <cstring>
using namespace std;

int		arr[1002];
int		visited[1002];
int		n;

void	init(void)
{
	memset(visited, -1, sizeof(visited));
	
}

void	solve(void)
{
	visited[0] = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<=arr[i]; j++)
		{
			if (visited[i+j] == -1)
				visited[i+j] = visited[i]+1;
			else
				visited[i+j] = min(visited[i+j], visited[i]+1);
		}
		if (visited[i] == -1)
		{
			visited[n-1] = -1;
			return ;
		}
	}
}



int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	init();
	solve();
	cout<<visited[n-1]<<'\n';
}