#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool	visit[10];
int		ans[10];
int		arr[10];
int		n, ret=0;

int		cal(void)
{
	int		ret=0;

	for(int i=1; i<n; i++)
		ret += abs(ans[i]-ans[i-1]);
	return (ret);
}

void	brute_force(int idx)
{
	if (idx == n)
	{
		ret = max(ret, cal());
		return ;
	}
	for(int i=0; i<n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			ans[idx] = arr[i];
			brute_force(idx+1);
			visit[i] = 0;
		}
	}
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	memset(visit, 0, sizeof(visit));
	brute_force(0);
	cout<<ret<<'\n';
}