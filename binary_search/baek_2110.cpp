#include <iostream>
#include <algorithm>
using namespace std;

#define	MAX	200002

int		arr[MAX];
int		n, c;

int		count(int val)
{
	int		ret=1, spot=arr[0];

	for(int i=1; i<n; i++)
		if (val <= arr[i]-spot)
		{
			spot = arr[i];
			ret++;
		}
	return (ret);
}

int		bs(long long left, long long right)
{
	long long mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (c <= count(mid))
		{
			ans = mid;
			left = mid+1;
		}
		else
			right = mid-1;
	}
	return(ans);
}	



int		main(void)
{
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);

	cin>>n>>c;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	cout<<bs(1, 1000000000)<<'\n';
}