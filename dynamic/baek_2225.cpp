#include <iostream>
#include <cstring>

using namespace std;

long long	val[202][202];
int			n, k;

long long	dp(int n, int k)
{
	if (k == 1 || n == 0)
		return (1);
	if (val[n][k])
		return (val[n][k]);
	else
	{
		for(int i=0; i<=n; i++)
		{
			val[n][k] += dp(i, k-1);
			val[n][k] %= 1000000000;
		}
		return (val[n][k]);
	}
}



int		main(void)
{
	cin>>n>>k;
	cout<<dp(n, k)<<'\n';
}