#include <iostream>
using namespace std;

bool	graph[102][102];
int		n;

void	floyd_warshall(void)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if(graph[j][i]&&graph[i][k])  // j->i와 i->k가 경로가 있으면,
					graph[j][k] = true;  // j->k 경로가 있음
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>graph[i][j];
	floyd_warshall();
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<graph[i][j]<<" ";
		cout<<'\n';
	}
}