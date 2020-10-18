#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

string	map[102];
int		visted[102][102];
int		w, h, ret;

void	init(void)
{
	ret = 0;
	memset(visted, 0, sizeof(visted));
}

void	bfs(void)
{
	queue<int>	q[3];
	int		x,y;

	visted[0][0] = 1;
	q[0].push(0);
	q[1].push(0);
	q[2].push(0);

	while (!q[0].empty())
	{
		y = q[0].front();
		x = q[1].front();
		ret = q[2].front();
		q[0].pop();
		q[1].pop();
		q[2].pop();
		ret++;
		if (x && !visted[y][x-1] && map[y][x-1] == '1')
		{
			q[0].push(y);
			q[1].push(x-1);
			q[2].push(ret);
			visted[y][x-1] = ret+1;
		}
		if (x != w-1 && !visted[y][x+1] && map[y][x+1] == '1')
		{
			q[0].push(y);
			q[1].push(x+1);
			q[2].push(ret);
			visted[y][x+1] = ret+1;
		}
		if (y && !visted[y-1][x] && map[y-1][x] == '1')
		{
			q[0].push(y-1);
			q[1].push(x);
			q[2].push(ret);
			visted[y-1][x] = ret+1;
		}
		if (y != h-1 && !visted[y+1][x] && map[y+1][x])
		{
			q[0].push(y+1);
			q[1].push(x);
			q[2].push(ret);
			visted[y+1][x] = ret+1;
		}
	}
}

int		main(void)
{
	init();
	cin>>h>>w;
	for(int i=0; i<h; i++)
		cin>>map[i];
	bfs();
	cout<<visted[h-1][w-1]<<'\n';
}