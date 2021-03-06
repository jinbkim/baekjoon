#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

string	map[101];
int		visted[101][101];
int		dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int		n, m;

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

int		bfs(void)
{
	queue< pair<int, int> >	q;
	int	cur_x, cur_y, next_x, next_y;

	q.push(pair<int, int>(0, 0));
	visted[0][0] = 1;
	while (!q.empty())
	{
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++)
		{
			next_x = cur_x+dir[i][0];
			next_y = cur_y+dir[i][1];
			if (is_inside(next_y, next_x) && map[next_y][next_x] == '1' && !visted[next_y][next_x])
			{
				visted[next_y][next_x] = visted[cur_y][cur_x]+1;
				q.push(pair<int, int> (next_y, next_x));
			}
		}
	}
	return (visted[n-1][m-1]);
}



int		main(void)
{
	init();
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>map[i];
	cout<<bfs()<<'\n';
}