#include <iostream>
#include <algorithm>
using namespace std;

int		arr[22][22];
int		n, ret=0;

void	solve(int idx)
{
	if (idx == 5)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				ret = max(ret, arr[i][j]);
		return ;
	}
	for(int i=0; i<n-1; i++)
	{
		
	}
}

int		main(void)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>arr[i][j];
	solve(0);
	cout<<ret<<'\n';
}