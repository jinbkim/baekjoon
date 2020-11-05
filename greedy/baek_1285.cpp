#include <iostream>

using namespace std;

#define MAX	22

char	map1[MAX][MAX];
bool	map2[MAX][MAX];
int		n;

int		greedy(void)
{
	int		ret = n*n;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			2
		}
}



int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>map1[i][j];
			if (map1[i][j] == 'H')
				map2[i][j] = true;
			else
				map2[i][j] = false;
		}
	cout<<greedy()<<'\n';
}