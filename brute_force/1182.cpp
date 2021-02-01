#include <iostream>
#include <cstring>
using namespace std;

bool		visit[22];
long long	arr[22];
long long	n, s, cnt=0;

void	brute_force(long long idx, long long sum)
{
	if (idx == n)
	{
		if (sum == s)
			cnt++;
		return ;
	}
	brute_force(idx+1, sum+arr[idx]);
	brute_force(idx+1, sum);
}

int		main(void)
{
	cin>>n>>s;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	memset(visit, 0, sizeof(visit));
	brute_force(0, 0);
	if (!s)
		cnt--;
	cout<<cnt<<'\n';
}