#include <iostream>
#include <cstring>
using namespace std;

long long	visited[102][22];
long long	arr[102];
long long	n, ret=0;

void		init(void)
{
	memset(visited, 0, sizeof(visited));
	visited[1][arr[1]] = 1;
}

long long	solve(void)
{
	for(int i=1; i<=n-2; i++)
		for(int j=0; j<=20; j++)
			if (visited[i][j])
			{
				if (j+arr[i+1] <= 20)
					visited[i+1][j+arr[i+1]] += visited[i][j];
				if (0 <= j-arr[i+1])
					visited[i+1][j-arr[i+1]] += visited[i][j];
			}
	return (visited[n-1][arr[n]]);
}



int			main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	init();	
	cout<<solve()<<'\n';
}