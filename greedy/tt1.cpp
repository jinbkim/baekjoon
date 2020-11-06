#include <iostream>
using namespace std;

#define MAX	52

char	map1[MAX][MAX];
char	map2[MAX][MAX];
int		n, m;

void	reverse(int y, int x)
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if (map1[y+i][x+j] == '1')
				map1[y+i][x+j] = '0';
			else
				map1[y+i][x+j] = '1';		
		}
}

int		greedy(void)
{
	int		ret=0;

	for(int i=1; i<=n-2; i++)
		for(int j=1; j<=m-2; j++)
			if (map1[i][j] != map2[i][j])
			{
				reverse(i, j);
				ret++;
			}
	for(int i=1; i<=n; i++)
		if (map1[i][m-1] != map2[i][m-1] || map1[i][m] != map2[i][m])
			ret = -1;
	for(int i=1; i<=m; i++)
		if (map1[n-1][i] != map2[n-1][i] || map1[n][i] != map2[n][i])
			ret = -1;
	return (ret);
}



int		main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map1[i][j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map2[i][j];
	cout<<greedy()<<'\n';
}