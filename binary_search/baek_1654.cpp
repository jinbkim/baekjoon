#include <iostream>

using namespace std;

int		arr[10001];
int		n, k, max_val;

bool	is_possible(long long mid)
{
	int	val = 0;

	for(int i=0; i<k; i++)
		val += arr[i]/mid;
	if (val < n)
		return (false);
	else
		return (true);
}

int		cut_line(void)
{
	long long	start, mid, end;
	int			ret;

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

	cin>>k>>n;
	max_val = 0;
	for(int i=0; i<k; i++)
	{
		cin>>arr[i];
		max_val = max(max_val, arr[i]);
	}
	cout<<cut_line()<<'\n';
}