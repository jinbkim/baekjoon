#include <iostream>
#include <algorithm>

using namespace std;

int		val[1002];
int		ret[1002];
int		n;

int		main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>val[i];
	ret[0] = 0;
	for(int i=1; i<=n; i++)
	{
		ret[i] = 0;
		for(int j=1; j<=i; j++)
			ret[i] = max(ret[i], ret[i-j]+val[j]);
	}
	cout<<ret[n]<<'\n';
}