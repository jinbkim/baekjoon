#include <iostream>
using namespace std;

int		main(void)
{
	int		n, m, k, cnt=0;

	cin>>n>>m>>k;
	while (1)
	{
		if (k<=cnt && n==2*m)
			break ;
		if (n <= 2*m)
			m--;
		else
			n--;
		cnt++;
	}
	cout<<m<<'\n';
}