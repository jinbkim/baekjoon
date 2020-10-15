#include <iostream>
#include <cstring>

using namespace	std;
int		val[12];

void	init(void)
{
	memset(val, 0, sizeof(val));
	val[1] = 1;
	val[2] = 2;
	val[3] = 4;
}

int		dp(int n)
{
	if(val[n])
		return (val[n]);
	else
	{
		val[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
		return (val[n]);
	}
}

int		main(void)
{
	int		t, data;

	init();
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>data;
		cout<<dp(data)<<'\n';
	}
}