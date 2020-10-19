#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int		map[1002][1002];
int		visted[1002][1002];
int		dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int		m, n, ret, cur_x, cur_y, next_x, next_y;

void	init(void)
{
	memset(visted, 0, sizeof(visted));
}

bool	is_inside(int y, int x)
{
	if (0 <= y && y <= n-1 && 0 <= x && x <= m-1)
		return (true);
	else
		return (false);
}

bool	is_error()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (!map[i][j] && !visted[i][j])
				return (true);
	return (false);
}

int		bfs(void)
{
	queue< pair<int, int> >	q;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (map[i][j] == 1)
			{
				q.push(pair<int, int>(i, j));
				visted[i][j] = 1;
			}
	while (!q.empty())
	{
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++)
		{
			next_x = cur_x+dir[i][0];
			next_y = cur_y+dir[i][1];
			if (is_inside(next_y, next_x) && !map[next_y][next_x] && !visted[next_y][next_x])
			{
				visted[next_y][next_x] = visted[cur_y][cur_x]+1;
				q.push(pair<int, int> (next_y, next_x));
			}
		}
	}
	return (visted[cur_y][cur_x] - 1);
}



int		main(void)
{
	init();
	cin>>m>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>map[i][j];
	ret = bfs();
	if (is_error())
		cout<<-1<<'\n';
	else
		cout<<ret<<'\n';
}