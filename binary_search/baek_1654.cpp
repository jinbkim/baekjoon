#include <iostream>
#include <algorithm>
using namespace std;

#define	MAX	10002

long long	arr[MAX];
long long	k, n;

bool	is_possible(long long val)
{
	long long 	cnt = 0;

	for(int i=0; i<k; i++)
		cnt += arr[i]/val;
	if (n <= cnt)
		return (true);
	else
		return (false);
}

long long	bs(long long left, long long right)
{
	long long	mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			left = mid+1;
			ans = mid;
		}
		else
			right = mid-1;
	}
	return (ans);
}



int		main(void)
{
   	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

	long long	max_range = 0;

	cin>>k>>n;
	for(int i=0; i<k; i++)
	{
		cin>>arr[i];
		max_range = max(max_range, arr[i]);
	}
	cout<<bs(1, max_range)<<'\n';
}