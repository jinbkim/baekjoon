#include <iostream>
#include <algorithm>
using namespace std;

#define	MAX	5002

int		arr[MAX];
int		n, m, max_range = 0;

bool	is_possible(int val)
{
	int	i, cnt, arr_min, arr_max;

	arr_min = MAX;
	arr_max = 0;
	cnt = 1;
	i = -1;
	while (++i < n)
	{
		arr_min = min(arr_min, arr[i]);
		arr_max = max(arr_max, arr[i]);
		if (val < arr_max-arr_min)
		{
			cnt++;
			arr_min = MAX;
			arr_max = 0;
		}
	}
	if (m < cnt)
		return (false);
	else
		return (true);
}

int		bs(int left, int right)
{
	int		mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			ans = mid;
			left = mid+1;
		}
		else
			right = mid-1;
	}
	return (ans);
}



int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>arr[i];
		if (max_range < arr[i])
			max_range = arr[i];
	}
	cout<<bs(1, max_range)<<'\n';
}