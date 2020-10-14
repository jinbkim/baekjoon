#include <iostream>
#include <algorithm>

using namespace std;

int		arr[200001];
int		n, c;

bool	is_possible(int mid)
{
	int	cnt, before;

	cnt = 1;
	before = arr[0];
	for(int i=1; i<n; i++)
	{
		if (arr[i] - before <= mid)
		{
			before = arr[i];
			cnt++;
		}
	}
	if (c <= cnt)
		return (true);
	else
		return (false);
}

int		install_router(void)
{
	int	low, mid, high, ret;

	low = arr[0];
	high = arr[n - 1];
	ret = 0;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (is_possible(mid))
		{
			ret = mid;
			low = mid+1;
		}
		else
			high = mid-1;
	}
	return (ret);
}



int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>c;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	cout<<install_router()<<'\n';
}