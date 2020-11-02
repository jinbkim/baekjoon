#include <iostream>
using namespace std;

long long	n, k;

long long	count(long long val)
{
	long long	ret=0;
	
	for(int i=1; i<=n; i++)
	{
		if (n <= val/i)
			ret += n;
		else
			ret += val/i;
	}
	return (ret);
}

long long	bs(long long left, long long right)
{
	long long	mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (k <= count(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	return (ans);
}



int		main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>k;
	cout<<bs(1, n*n)<<'\n';
}