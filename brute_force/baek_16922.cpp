#include <iostream>
#include <cstring>
using namespace std;

bool	value[1002];
bool	dp[22][1002];
int		dir[4] = {1, 5, 10, 50};
int		n, ret=0;

void	init(void)
{
	memset(value, 0, sizeof(value));
	memset(dp, 0, sizeof(dp));	
}

void	solve(int idx, int val)
{
	if (dp[idx][val])
		return ;
	dp[idx][val] = true ;
	if (idx == n)
	{
		if (!value[val])
		{
			value[val] = true;
			ret++;
		}
		return ;
	}
	for(int i=0; i<4; i++)
		solve(idx+1, val+dir[i]);
}



int		main(void)
{
	init();
	cin>>n;
	solve(0, 0);
	cout<<ret<<'\n';
}