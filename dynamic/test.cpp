#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int		arr[302][22];
int		k, l, m, n;

void	init(void)
{
	memset(arr, 0, sizeof(arr));
}

int		solve(int idx, int invest, int profit)
{
	int		ret=0;

	if (m < idx)
		return (0);
	for(int i=0; i<=n; i++)
	{
		if (invest+i <= n)
			ret = max(ret, arr[i][idx]+solve(idx+1, invest+i, profit+arr[i][idx]));
	}
	cout<<"idx : "<<idx<<", invest : "<<invest<<", profit : "<<profit<<", ret : "<<ret<<'\n';
	return (ret);
}

int		main(void)
{
	init();
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>l;
		for(int j=1; j<=m; j++)
		{
			cin>>k;
			arr[i+1][j] = k;
		}
	}
	// for(int i=0; i<=n; i++)
	// {
	// 	for(int j=0; j<=m; j++)
	// 	{
	// 		cout<<"i : "<<i<<", j : "<<j<<", arr[i][j] : "<<arr[i][j]<<'\n';
	// 	}
	// }
		
	cout<<solve(1, 0, 0)<<'\n';
}