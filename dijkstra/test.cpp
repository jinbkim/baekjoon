#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

char	map[102][102];
int		dis[102][102];
int		dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int		m, n;

void	dijkstra(void)
{
	priority_queue< pair<int, pair<int, int> > >	pq;
	int	w, x, y, next_w, next_x, next_y;

	pq.push(make_pair(0, make_pair(1, 1)));
	while (!pq.empty())
	{
		x = pq.top().second.second;
		y = pq.top().second.first;
		w = -pq.top().first;  // 최대힙을 최소힙처럼 사용하기위해
		pq.pop();
		if (dis[y][x] < w)
			continue ;
		for(int i=0; i<4; i++)
		{
			next_x = x+dir[i][0];
			next_y = y+dir[i][1];
			if (1<=next_x && next_x<=m && 1<=next_y && next_y<=n)
			{
				next_w = w+map[next_y][next_x]-'0';
				if (next_w < dis[next_y][next_x])
				{
					dis[next_y][next_x] = next_w;
					// 최대힙을 최소힙처럼 사용하기위해
					pq.push(make_pair(-next_w, make_pair(next_y, next_x)));
				}
			}
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>m>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			cin>>map[i][j];
			dis[i][j] = 987654321;
		}
	dijkstra();
	// 입력에 (1,1)과 (n,m)이 뚤려있다고 가정했는데 그렇지 않은 입력값이 들어오는것 같음
	if (dis[n][m] == 987654321)
		cout<<0<<'\n';
	else
		cout<<dis[n][m]<<'\n';
}