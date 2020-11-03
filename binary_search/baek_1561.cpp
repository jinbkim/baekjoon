#include <iostream>
using namespace std;

long long	arr[10002];
long long	n, m;

long long	count(long long val)
{
	long long	ret=m;
	
	for(int i=1; i<=m; i++)
		ret += val/arr[i];
	return (ret);
}

long long	bs(long long left, long long right)
{
	long long	mid, ans, diff;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (n <= count(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	diff = count(ans)-n;
	while (1)
	{
		if (!(ans % arr[m]))
			diff--;
		if (diff < 0)
			break ;
		m--;
	}
	return (m);
}



int		main(void)
{
	cin>>n>>m;
	for(int i=1; i<=m; i++)
		cin>>arr[i];
	cout<<bs(0, 60000000002)<<'\n';
}