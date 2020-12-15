#include <iostream>
#include <algorithm>
using namespace std;

long long	num[13];
long long	n, pl, mi, mu, di, max_v=-987654321, min_v=987654321;

// a:pl, b:mi, c:mu, d:di 의 개수
void	dfs(long long idx, long long a, long long b, long long c, long long d, long long ret)
{
	if (idx == n-1)  // 최대 깊이까지오면 최대값과 최소값을 갱신
	{
		max_v = max(max_v, ret);
		min_v = min(min_v, ret);
		return ;
	}
	if (a+1 <= pl)
		dfs(idx+1, a+1, b, c, d, ret+num[idx+1]);
	if (b+1 <= mi)
		dfs(idx+1, a, b+1, c, d, ret-num[idx+1]);
	if (c+1 <= mu)
		dfs(idx+1, a, b, c+1, d, ret*num[idx+1]);
	if (d+1 <= di)
		dfs(idx+1, a, b, c, d+1, ret/num[idx+1]);
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>num[i];
	cin>>pl>>mi>>mu>>di;
	dfs(0, 0, 0, 0, 0, num[0]);
	cout<<max_v<<'\n';
	cout<<min_v<<'\n';
}