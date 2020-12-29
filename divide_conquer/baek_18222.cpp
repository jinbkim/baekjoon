#include <iostream>
#include <unistd.h>
using namespace std;

long long	k, d;  // 입력이 10^18 이므로 int로는 감당못함

void	divide(long long val, long long cnt)
{
	if (val == 1)
	{
		if (cnt % 2)
			cout<<1<<'\n';
		else
			cout<<0<<'\n';
		exit(0);
	}
	for(; val<=d; d/=2)
		;
	divide(val-d, cnt+1);
}

int		main(void)
{
	cin>>k;
	for(d=1; d<k; d*=2)
		;
	divide(k, 0);
}