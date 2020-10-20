#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>	vec;
int		map[102][102];
int		visted[102][102];
int		dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0,1}};
int		pos[4];
int		m, n, k, cnt;

void	init(void)
{
	memset(visted, 0, sizeof(visted));
	memset(map, 0, sizeof(map));
}

bool	is_inside(int y, int x)
{
	if (0 <= x && x <= n-1 && 0 <= y && y <= m-1)
		return (true);
	else
		return (false);
}

void	dfs(int y, int x)
{
	int	next_x, next_y;

	if (visted[y][x] || map[y][x])
		return ;
	visted[y][x] = 1;
	cnt++;
	for(int i=0; i<4; i++)
	{
		next_x = x+dir[i][0];
		next_y = y+dir[i][1];
		if(is_inside(next_y, next_x) && !visted[next_y][next_x] && !map[next_y][next_x])
			dfs(next_y, next_x);
	}
}



int		main(void)
{
	init();
	cin>>m>>n>>k;
	for(int i=0; i<k; i++)
	{
		for(int j=0; j<4; j++)
			cin>>pos[j];
		for(int j=pos[1]; j<pos[3]; j++)
			for(int k=pos[0]; k<pos[2]; k++)
				map[j][k] = 1;
	}
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
		{
			cnt = 0;
			dfs(i, j);
			if (cnt)
				vec.push_back(cnt);
		}
	sort(vec.begin(), vec.end());
	cout<<vec.size()<<'\n';
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<' ';
	cout<<'\n';
}