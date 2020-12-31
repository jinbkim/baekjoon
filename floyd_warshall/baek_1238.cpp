#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define	INF	987654321

int		dis[1002][1002];
int		ans[1002];
int		n, m, x, from, to, cost, ret=0;

void	floyd_warshall(void)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if (dis[j][i]+dis[i][k] < dis[j][k])
					dis[j][k] = dis[j][i]+dis[i][k];
}

int		main(void)
{
	cin>>n>>m>>x;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = INF;
		}
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>cost;
		dis[from][to] = cost;
	}
	floyd_warshall();
	memset(ans, 0, sizeof(ans));
	for(int i=1; i<=n; i++)
		ans[i] = dis[x][i]+dis[i][x];
	sort(ans, ans+n+1);
	cout<<ans[n];  // 최대값 출력
}