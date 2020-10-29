#include <iostream>
#include <algorithm>
using namespace std;

#define	MAX 100002

int		arr1[MAX], arr2[MAX];
int		n, m, max_range;

int		get_m(int val)
{
	int i, temp, ret;

	ret = 1;
	temp = 0;
	i=-1;
	while (++i != n)
	{
		temp += arr1[i];
		if (val < arr1[i])
			return (MAX);
		if (val < temp)
		{
			temp = arr1[i];
			ret++;
		}
	}
	return (ret);
}

int		bs(void)
{
	int	left, right, mid, ans;

	left = 1;
	right = max_range;
	while (left <= right)
	{
		mid = (left+right)/2;
		if (m < get_m(mid))
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
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>arr1[i];
		arr2[i] = arr1[i];
	}
	sort(arr2, arr2+n);
	max_range = 0;
	for(int i=0; i<=n/m; i++)
		max_range += arr2[n-1-i];
	cout<<bs()<<'\n';
}