#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

char	map[51][51];
int		visted[51][51];
int		m, n, ret;

void	init(void)
{
	memset(map, 0, sizeof(map));
	memset(visted, 0, sizeof(visted));
	ret = 0;
}

void	bfs(int y, int x)
{
	queue <pair <int, int> >	q;

	if (visted[y][x] || !map[y][x])
		return ;
	ret++;
	visted[y][x] = true;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (x && !visted[y][x-1] && map[y][x-1])
		{
			q.push(make_pair(y, x-1));
			visted[y][x-1] = true;
		}
		if (x != m-1 && !visted[y][x+1] && map[y][x+1])
		{
			q.push(make_pair(y, x+1));
			visted[y][x+1] = true;
		}
		if (y && !visted[y-1][x] && map[y-1][x])
		{
			q.push(make_pair(y-1, x));
			visted[y-1][x] = true;
		}
		if (y != n-1 && !visted[y+1][x] && map[y+1][x])
		{
			q.push(make_pair(y+1, x));
			visted[y+1][x] = true;
		}
	}
}



int		main(void)
{
	int		t, k;

	cin>>t;
	for (int i=0; i<t; i++)
	{
		init();
		cin>>m>>n>>k;
		for (int j=0; j<k; j++)
		{
			int		px, py;

			cin>>px>>py;
			map[py][px] = true;
		}
		for(int j=0; j<n; j++)
			for(int k=0; k<m; k++)
				bfs(j, k);
		cout<<ret<<'\n';
	}	
}