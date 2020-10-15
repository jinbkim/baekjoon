#include <iostream>
#include <cstring>

using namespace std;

int		val[1001];

void	init(void)
{
	memset(val, 0, sizeof(val));
	val[1] = 1;
	val[2] = 2;
}

int		dp(int n)
{
	if (val[n])
		return (val[n]);
	else
	{
		val[n] = (dp(n-1) + dp(n-2)) % 10007;
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