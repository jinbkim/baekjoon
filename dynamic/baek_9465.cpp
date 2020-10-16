#include <iostream>
#include <algorithm>

using namespace	std;

int		flag[3][100001];
int		arr[2][100001];
int		n;

void	dp(void)
{
	flag[0][0] = arr[0][0];
	flag[1][0] = arr[1][0];
	flag[2][0] = 0;
	for(int i=1; i<n; i++)
	{
		flag[0][i] = max(flag[1][i-1], flag[2][i-1]) + arr[0][i];
		flag[1][i] = max(flag[2][i-1], flag[0][i-1]) + arr[1][i];
		flag[2][i] = max(flag[0][i-1], flag[1][i-1]);
	}
}



int		main(void)
{
	int		t;

	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		for(int j=0; j<n; j++)
			cin>>arr[0][j];
		for(int j=0; j<n; j++)
			cin>>arr[1][j];
		dp();
		cout<<max(max(flag[0][n-1], flag[1][n-1]), flag[2][n-1])<<'\n';
	}
}