#include <iostream>
using namespace std;

#define	MAX 52

char	map1[MAX][MAX];
char	map2[MAX][MAX];
int		n, m;

int		greedy(void)
{
	int 	ret=0;

	for(int i=1; i<=n-2; i++)
		for(int j=1; j<=m-2; j++)
		{
			if (map1[i][j] != map2[i][j])
			{
				ret++;
				for(int k=0; k<3; k++)
					for(int l=0; l<3; l++)
					{
						if (map1[i+k][j+l] == '1')
							map1[i+k][j+l] = '0';
						else
							map1[i+k][j+l] = '1';
					}
			}
		}
	for(int i=1; i<=m; i++)
		if (map1[n-1][i] != map2[n-1][i] || map1[n][i] != map2[n][i])
			return (-1);
	for(int i=1; i<=n; i++)
		if (map1[i][m-1] != map2[i][m-1] || map1[i][m] != map2[i][m])
			return (-1);
	return (ret);
}



int		main(void)
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map1[i][j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map2[i][j];
	cout<<greedy()<<'\n';
}