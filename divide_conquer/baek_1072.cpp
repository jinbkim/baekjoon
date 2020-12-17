#include <iostream>
using namespace std;

long long	x, y, z;

bool		is_change(long long val)  // 승률이 바뀌면 true 아니면 false
{
	if ((y+val)*100/(x+val) == z)
		return (false);
	else
		return (true);
}

long long	binary_search(long long left, long long right)
{
	long long	mid, ret;

	while(left <= right)
	{
		mid = (left+right)/2;
		if (is_change(mid))
		{
			ret = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	return (ret);
}

int		main(void)
{
	cin>>x>>y;
	z = y*100/x;
	if (z==100 || z==99)  // 승률이 절대 안바뀌는 경우
		cout<<-1<<'\n';
	else
		cout<<binary_search(1, 1000000000)<<'\n';
}