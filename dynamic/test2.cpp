#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int		diff[102];
bool	dp[1002][102];
int		n, s, m, ret=-1;

void	guitar(int start, int idx)
{
	if (n < idx || dp[start][idx])
		return ;
	dp[start][idx] = true;
	if (idx == n)
	{
		ret = max(ret, start);
		return ;
	}
	if (start+diff[idx+1] <= m)
		guitar(start+diff[idx+1], idx+1);
	if (0 <= start-diff[idx+1])
		guitar(start-diff[idx+1], idx+1);
}



int		main(void)
{
	memset(dp, 0, sizeof(dp));
	cin>>n>>s>>m;
	for(int i=1; i<=n; i++)
		cin>>diff[i];
	guitar(s,0);
	cout<<ret<<'\n';
}