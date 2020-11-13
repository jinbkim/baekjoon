#include <iostream>
#include <cstring>
using namespace std;

#define MAX	102

int		main(void)
{
	long long	arr[MAX][MAX];
	long long	visted[MAX][MAX];
	int		n;

	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>arr[i][j];

	memset(visted, 0, sizeof(visted));		
	visted[1][1] = 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if (!arr[i][j])
				break ;
			if (i+arr[i][j] <= n)
				visted[i+arr[i][j]][j] += visted[i][j];
			if (j+arr[i][j] <= n)
				visted[i][j+arr[i][j]] += visted[i][j];
		}
	cout<<visted[n][n]<<'\n';
}