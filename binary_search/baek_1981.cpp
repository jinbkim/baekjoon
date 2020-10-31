#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define	MAX	202

int		map[MAX][MAX];
int		dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
int		visited[MAX][MAX];
int		n, min_range = MAX, max_range = 0;

bool	bfs(int val)
{
	queue< pair<int, int> >	q;
	int		x, y, new_x, new_y;

	for(int i=min_range; i<=max_range; i++)
	{
		memset(visited, true, sizeof(visited));
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if (i <= map[j][k] && map[j][k] <= i+val)
					visited[j][k] = false;
		q.push(make_pair(1, 1));
		while (!q.empty())
		{
			x = q.front().second;
			y = q.front().first;
			q.pop();
			if (visited[y][x])
				continue ;
			visited[y][x] = true;
			if (y == n && x == n)
				return (true);
			for(int j=0; j<4; j++)
			{
				new_x = x+dir[j][0];
				new_y = y+dir[j][1];
				if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= n)
					q.push(make_pair(new_y, new_x));
			}
		}
	}
	return (false);
}

int		bs(int left, int right)
{
	int		mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (bfs(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	return (ans);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			cin>>map[i][j];
			min_range = min(min_range, map[i][j]);
			max_range = max(max_range, map[i][j]);
		}
	cout<<bs(0, max_range)<<'\n';
}