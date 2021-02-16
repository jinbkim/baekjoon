#include <iostream>
using namespace std;

int		main(void)
{
	int		change[] = {500, 100, 50, 10, 5, 1};
	int		m, i=-1, ret=0;

	cin>>m;
	m = 1000-m;
	while (++i < 6)
		while(change[i] <= m && ++ret)
			m -= change[i];
	cout<<ret<<'\n';
}
