#include <iostream>
#include <cstring>

using namespace std;

long long	val[92];

void		init(void)
{
	memset(val, 0, sizeof(val));
	val[1] = 1;
	val[2] = 1;
}

long long	dp(int n)
{
	if (val[n])
		return (val[n]);
	else
	{
		val[n] = (dp(n-1) + dp(n-2));
		return (val[n]);
	}
}



int		main(void)
{
	int		n;

	init();
	cin>>n;
	cout<<dp(n)<<'\n';
}