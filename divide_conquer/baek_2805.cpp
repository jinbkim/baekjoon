#include <iostream>
using namespace std;

#define	MAX	1000002

int		arr[MAX];
int		n, m, max_range = 0;

long long	get_tree(long long	val)
{
	long long	ret = 0;

	for(int i=0; i<n; i++)
		if (arr[i]-val > 0)
			ret += arr[i]-val;
	return (ret);
}

long long	bs(long long left, long long right)
{
	long long	mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (m <= get_tree(mid))
		{
			ans = mid;
			left = mid+1;
		}
		else
			right = mid-1;
	}
	return (ans);
}



int			main(void)
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<bs(1, 2000000000)<<'\n';
}