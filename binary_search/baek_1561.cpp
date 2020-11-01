#include <iostream>
#include <vector>
using namespace std;

#define MAX	60000000000

vector<long long>	vec;
long long	n, m, cnt;

long long	count_num(long long val)
{
	long long	ret;

	ret = m;
	for(int i=0; i<m; i++)
		ret += val/vec[i];
	return (ret);
}

long long	bs(long long left, long long right)
{
	long long	mid, ans, diff, idx;

	ans = 0;
	while (left <= right)
	{
		mid = (left+right)/2;
		if (n <= count_num(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	diff = count_num(ans)-n;
	idx = m;
	while (1)
	{
		idx--;
		if (!(ans%vec[idx]))
			diff--;
		if (diff < 0)
			break;
	}
	return (idx+1);
}




int		main(void)
{
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

	long long	data;

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>data;
		vec.push_back(data);
	}
	cout<<bs(0, MAX)<<'\n';
}