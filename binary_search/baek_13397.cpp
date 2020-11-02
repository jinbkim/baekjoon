#include <iostream>
#include <algorithm>
using namespace	std;

#define MAX	10002

int		arr[MAX];
int		n, m;

int		count(int val)
{
	int		ret=1, arr_min=MAX, arr_max=0;

	for(int i=0; i<n; i++)
	{
		arr_min = min(arr_min, arr[i]);
		arr_max = max(arr_max, arr[i]);
		if (val < arr_max-arr_min)
		{
			ret++;
			arr_min = arr[i];
			arr_max = arr[i];
		}
	}
	return (ret);
}

int		bs(int left, int right)
{
	int		mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (count(mid) <= m)
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

	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<bs(0, MAX)<<'\n';
}