#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define	MAX	202

int		map[MAX][MAX];
int		dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
int		visited[MAX][MAX];
int		n, max_range = 0, min_val, max_val;

void	bfs(int y, int x, int val)
{
	queue< pair<int, int> >	q;


	// int		new_x, new_y;

	// if (visited[y][x])
	// 	return ;
	// min_val = min(min_val, map[y][x]);
	// max_val = max(max_val, map[y][x]);
	// if (val < max_val-min_val)
	// 	return ;
	// cout<<"x : "<<x<<", y : "<<y<<", val :"<<val<<'\n';
	// cout<<"min : "<<min_val<<'\n';
	// cout<<"max : "<<max_val<<'\n';
	// visited[y][x] = true;
	// for (int i=0; i<4; i++)
	// {
	// 	new_x = x+dir[i][0];
	// 	new_y = y+dir[i][1];
	// 	if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= n)
	// 	{
	// 		// min_val = min(min_val, map[y][new_x]);
	// 		// max_val = max(max_val, map[y][x]);
	// 		// if (max_val-min_val <= val)
	// 			dfs(new_y, new_x, val);
	// 	}
	// }
}

void	dfs(int y, int x, int val)
{
	int		new_x, new_y, temp1, temp2;

	if (visited[y][x])
		return ;
	temp1 = min_val;
	temp2 = max_val;
	min_val = min(min_val, map[y][x]);
	max_val = max(max_val, map[y][x]);

	// cout<<"--x : "<<x<<", y : "<<y<<", val :"<<val<<'\n';
	// cout<<"--min : "<<min_val<<'\n';
	// cout<<"--max : "<<max_val<<'\n';

	if (val < max_val-min_val)
	{
		min_val = temp1;
		max_val = temp2;
		return ;
	}
	cout<<"x : "<<x<<", y : "<<y<<", val :"<<val<<'\n';
	cout<<"min : "<<min_val<<'\n';
	cout<<"max : "<<max_val<<'\n';
	visited[y][x] = true;
	for (int i=0; i<4; i++)
	{
		new_x = x+dir[i][0];
		new_y = y+dir[i][1];
		if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= n)
		{
			// min_val = min(min_val, map[y][new_x]);
			// max_val = max(max_val, map[y][x]);
			// if (max_val-min_val <= val)
				dfs(new_y, new_x, val);
		}
	}
}

bool	is_possible(int val)
{
	memset(visited, 0, sizeof(visited));
	min_val = MAX;
	max_val = 0;
	dfs(1, 1, val);
	if (visited[n][n])
		return (true);
	else
		return (false);
}

int		bs(int left, int right)
{
	int		mid, ans;

	while (left <= right)
	{
		mid = (left+right)/2;
		if (is_possible(mid))
		{
			cout<<"pissible : "<<mid<<'\n';
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
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			cin>>map[i][j];
			if (max_range < map[i][j])
				max_range = map[i][j];
		}
	cout<<bs(0, max_range)<<'\n';
}