#include <iostream>
#include <cstring>
using namespace std;

long long	arr[7][7];
long long	ret[7][7];
long long	n, squ;

void	cal(long long ret[7][7], long long arr[7][7])
{
	long long	temp[7][7];

	memset(temp, 0, sizeof(temp));
	for(int j=1; j<=n; j++)
		for(int k=1; k<=n; k++)
			for(int l=1; l<=n; l++)
				temp[j][k] += arr[j][l]*ret[l][k];
	for(int j=1; j<=n; j++)
		for(int k=1; k<=n; k++)
			ret[j][k] = temp[j][k]%1000;
}

int		main(void)
{
	memset(ret, 0, sizeof(ret));
	cin>>n>>squ;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			cin>>arr[i][j];
		ret[i][i] = 1;
	}
	while (squ > 0)
	{
		if (squ % 2)
			cal(ret, arr);
		cal(arr, arr);
		squ /= 2;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			cout<<ret[i][j]<<' ';
		cout<<'\n';
	}
}