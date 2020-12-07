#include <iostream>
using namespace std;

#define	MAX 100002

long long	arr[MAX];
long long	n, m;

long long	count(long long val)
{
	long long	ret = 1, sum = 0;

	for(int i=0; i<n; i++)
	{
		if (val < arr[i])
			return (m+1);
		sum += arr[i];
		if (val < sum)
		{
			ret++;
			sum = arr[i];
		}
	}
	return (ret);
}

long long	bs(long long left, long long right)
{
	long long mid, ans, cnt;

	while (left <= right)
	{
		mid = (left+right)/2;
		cnt = count(mid);
		if (m < cnt)
			left = mid+1;
		else
		{
			ans = mid;
			right = mid-1;
		}
	}
	return (ans);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<bs(1, 1000000000)<<'\n';
}