#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define	MAX 102
#define	INF	987654321

typedef	struct	s_info
{
	int		x;
	int		y;
	int		w;
}				t_info;

vector <t_info>	vec[MAX][MAX];
t_info	info;
string	map[MAX];
long long	min_d[MAX][MAX];
int		dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
int		n, m, x1, x2, y1, y2, w1, w2;

void	init(void)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			min_d[i][j] = INF;
	min_d[1][1] = 0;
}

void	info_init(t_info *in, int x, int y, int w)
{
	in->x = x;
	in->y = y;
	in->w = w;
}

int		dijkstra(int n, int m)
{
	priority_queue<t_info>	pq;

	info_init(&info, 1, 1, 0);
	pq.push(info);
	pq.pop();
	while(!pq.empty())
	{
		x1 = pq.top().x;
		y1 = pq.top().y;
		w1 = pq.top().w;
		pq.pop();
		for(int i=0; i<vec[y1][x1].size(); i++)
		{
			x2 = vec[y1][x1][i].x;
			y2 = vec[y1][x1][i].y;
			w2 = vec[y1][x1][i].w;
			if (min_d[y1][x1]+w2 <= min_d[y2][x2])
			{
				min_d[y2][x2] = min_d[y1][x1]+w2;
				info_init(&info, x2, y2, w2);
				pq.push(info);
			}
		}
	}
	return(min_d[n][m]);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			cin>>map[i][j];
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			for(int k=0; k<4; k++)
			{
				y1 = i+dir[k][0];
				x1 = j+dir[k][1];
				if (1 <= x1 && x1 <= m && 1 <= y1 && y1 <= n && map[y1][x1] == '1')
				{
					info_init(&info, x1, y1, 1);
					vec[y1][x1].push_back(info);
				}
				else if (1 <= x1 && x1 <= m && 1 <= y1 && y1 <= n && map[y1][x1] == '0')
				{
					info_init(&info, x1, y1, 0);
					vec[y1][x1].push_back(info);
				}
			}
	init();
	cout<<dijkstra(n, m)<<'\n';
}