#include <iostream>
#include <cstring>

using namespace std;

long long	val[1002];

void		init(void)
{
	memset(val, 0, sizeof(val));
	val[1] = 1;
	val[2] = 3;
}

long long	dp(int n)
{
	if (val[n])
		return (val[n]);
	else
	{
		val[n] = (dp(n-1) + 2*dp(n-2)) % 10007;
		return (val[n]);
	}
}



int		main(void)
{
	int		n;

	cin>>n;
	init();
	cout<<dp(n)<<'\n';
}