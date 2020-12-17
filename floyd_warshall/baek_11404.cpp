#include <iostream>
#include <algorithm>
using namespace std;
#define	INF 987654321

int		dis[102][102];
int		n, m, from, to, w;

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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if (i == j)
				dis[i][j] = 0;  // 자기자신의 거리는 0
			else
				dis[i][j] = INF;  // 최단거리를 매우 큰값으로 초기화
		}
	for(int i=1; i<=m; i++)
	{
		cin>>from>>to>>w;
		dis[from][to] = min(dis[from][to], w);  // 더 작은값이 들어오면 바꿔줌
	}
	floyd_warshall();
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if (dis[i][j] == INF)
				cout<<0<<' ';
			else
				cout<<dis[i][j]<<" ";
		}
		cout<<'\n';
	}
}