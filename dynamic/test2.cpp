#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int		arr[302][22];
int		ans[22];
int		k, l, m, n, ret=0;

void	init(void)
{
	memset(arr, 0, sizeof(arr));
}

void	solve(int idx, int invest, int profit)
{
	int		temp;

	if (m < idx)
	{
		temp = ret;
		ret = max(ret, profit);
		if (temp != ret)
		{
			
		}
		return ;
	}
	for(int i=0; i<=n; i++)
		if (invest+i <= n)
		{
			ans[idx] = i;
			solve(idx+1, invest+i, profit+arr[i][idx]);
		}
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
	solve(1, 0, 0);
	cout<<ret<<'\n';
}