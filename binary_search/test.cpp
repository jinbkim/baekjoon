#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 5002

int     arr[MAX];
int     n, m, max_range = 0;

int		count_section(int diff)
{
	int		i, ret, min_val, max_val;

	ret = 1;
	min_val = arr[0];
	max_val = arr[0];
	for(int i=1; i<n; i++)
	{
		min_val = min(arr[i], min_val);
		max_val = max(arr[i], max_val);
		if (diff < max_val-min_val)
		{
			min_val = arr[i];
			max_val = arr[i];
			ret++;
		}
	}
	return (ret);
}

int     bs(int left, int right)
{
	int		mid, ans;

	while(left <= right)
	{
		mid = (left+right)/2;
		if (count_section(mid) <= m)
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	return (ans);
}



int     main(void)
{
 	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
		max_range = max(max_range, arr[i]);
    }
    cout<<bs(0, max_range)<<'\n';
}