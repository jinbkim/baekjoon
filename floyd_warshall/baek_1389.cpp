#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF	987654321

int		dis[102][102];
int		ans[102];
int		n, m, from, to, ret_idx, ret_val;

void	floyd_warshall(void)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if(dis[j][i]!=INF && dis[i][k]!=INF)
					dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
}

void	init(void)
{
	memset(ans, 0, sizeof(ans));
	ret_idx = n;
	ret_val = INF;
}

int		main(void)
{
	cin>>n>>m;
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
		cin>>from>>to;
		dis[from][to] = 1;
		dis[to][from] = 1;
	}
	floyd_warshall();
	init();
	for(int i=n; 1<=i; i--)
	{
		for(int j=1; j<=n; j++)
			ans[i] += dis[i][j];  // 케빈 베이컨 수
		ret_val = min(ret_val, ans[i]);  // 케빈 베이컨의 수 최소값 구하기
		if (ret_val == ans[i])  //  케빈 베이컨의 최소값이 바뀌면
			ret_idx = i;  // 답을 갱신
	}
	cout<<ret_idx<<'\n';
}