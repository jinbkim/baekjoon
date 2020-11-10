#include <iostream>
using namespace std;

int		main(void)
{
	int		ret, n , m;
	cin>>n>>m;
	if (n == 1)
		ret = 1;
	else if (n == 2)
	{
		if (m < 7)
			ret = (m+1)/2;
		else
			ret = 4;
	}
	else
	{
		if (m <= 4)
			ret = m;
		else if (m == 5)
			ret = 4;
		else
			ret = m-2;
	}
	cout<<ret<<'\n';
}