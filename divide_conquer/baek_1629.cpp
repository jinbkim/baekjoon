#include <iostream>

using namespace std;

int		a, b, c;

long long	mul(int a, int b, int c)
{
	long long	temp;

	if (b == 0)
		return (1);
	temp = mul(a, b/2, c);
	if (b % 2)
		return (temp * temp % c * a %c);
	else
		return (temp * temp % c);
}



int			main(void)
{
	cin>>a>>b>>c;
	cout<<mul(a, b, c) % c<<'\n';
}