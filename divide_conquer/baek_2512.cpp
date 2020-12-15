#include <iostream>
using namespace std;

long long	money[10002];
long long	n, m, big=0, sum=0;

// 구한 상한액으로 배정받을수 있는지 없는지
bool		is_possible(long long val)
{
	sum=0;
	for(int i=0; i<n; i++)
	{
		if (val < money[i])
			sum += val;
		else
			sum += money[i];
	}
	if (m < sum)
		return (false);
	else
		return (true);
}

long long	binary_search(long long left, long long right)
{
	long long	mid, ret;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			ret = mid;
			left = mid+1;
		}
		else
			right = mid-1;
	}
	return (ret);
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>money[i];
		sum += money[i];  // 입력의 총합
		big = max(big, money[i]);  // 입력의 최대값
	}
	cin>>m;
	if (sum < m)  // 요청한 금액을 그대로 배정받을수 있을경우
		cout<<big<<'\n';
	else
		cout<<binary_search(0, big)<<'\n';
}