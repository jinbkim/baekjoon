#include <iostream>

using namespace std;

int		arr[1000001];
int		n, m, max_val;

bool	is_possible(long long mid)
{
	long long	sum = 0;

	for(int i=0; i<n; i++)
		if (mid < arr[i])
			sum += arr[i] - mid;
	if (sum < m)
		return (false);
	else
		return (true);
}

int		cut_tree(void)
{
	long long	start, mid, end, ret;

	start = 1;
	end = max_val;
	ret = 0;
	while (start<=end)
	{
		mid = (start+end)/2;
		if (is_possible(mid))
		{
			ret = mid;
			start = mid+1;
		}
		else
			end = mid-1;
	}
	return (ret);
}



int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n>>m;
	max_val = 0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		max_val = max(max_val, arr[i]);
	}
	cout<<cut_tree()<<'\n';
}