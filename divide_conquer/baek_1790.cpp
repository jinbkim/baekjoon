#include <iostream>
#include <cmath>
using namespace std;

long long	n, k;

long long	get_size(int val)
{
	long long	ret;
	int			i, j;

	ret = 0;
	for(i=1,j=1; j<=val/10; i++,j*=10)
		ret += i*j*9;
	ret += (val-(j-1))*i;
	return (ret);
}

char		bs(long long left, long long right)
{
	string	str;
	long long mid, ans;
	int		str_size;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (k <= get_size(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	str = to_string(ans);
	return (str[str.size()-(get_size(ans)-k)-1]);
}



int			main(void)
{
	cin>>n>>k;
	if (get_size(n) < k)
		cout<<-1<<'\n';
	else
		cout<<bs(1, n)<<'\n';
}