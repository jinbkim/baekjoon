#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int		map[102][102][102];
int		visted[102][102][102];
int		dir[6][3] = {{0,0,1}, {0,1,0}, {1,0,0}, {0,0,-1}, {0,-1,0}, {-1,0,0}};
int		m, n, h, ret, cur_x, cur_y, cur_z, next_x, next_y, next_z;

void	init(void)
{
	memset(visted, 0, sizeof(visted));
}

bool	is_inside(int z, int y, int x)
{
	if (0<= z && z <= h-1 && 0 <= y && y <= n-1 && 0 <= x && x <= m-1)
		return (true);
	else
		return (false);
}

int		bfs(void)
{
	queue< pair<pair<int, int>, int> >	q;
	for(int i=0; i<h; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<m; k++)
				if (map[i][j][k] == 1)
				{
					q.push(pair<pair<int, int>, int>(make_pair(make_pair(i, j), k)));
					visted[i][j][k] = 1;
				}
	while (!q.empty())
	{
		cur_z = q.front().first.first;
		cur_y = q.front().first.second;
		cur_x = q.front().second;
		q.pop();
		for(int i=0; i<6; i++)
		{
			next_x = cur_x+dir[i][0];
			next_y = cur_y+dir[i][1];
			next_z = cur_z+dir[i][2];
			if (is_inside(next_z, next_y, next_x) && !map[next_z][next_y][next_x] && !visted[next_z][next_y][next_x])
			{
				visted[next_z][next_y][next_x] = visted[cur_z][cur_y][cur_x]+1;
				q.push(pair<pair<int, int>, int>(make_pair(make_pair(next_z, next_y), next_x)));
			}
		}
	}
	return (visted[cur_z][cur_y][cur_x] - 1);
}

bool	is_error()
{
	for(int i=0; i<h; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<m; k++)
			if (!map[i][j][k] && !visted[i][j][k])
				return (true);
	return (false);
}



int		main(void)
{
	init();
	cin>>m>>n>>h;
	for(int i=0; i<h; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<m; k++)
				cin>>map[i][j][k];
	ret = bfs();
	if (is_error())
		cout<<-1<<'\n';
	else
		cout<<ret<<'\n';
}