#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int		n = 7;
int		visted[8];
vector<int>	vec[8];

void	dfs(int x)
{
	if (visted[x])
		return ;
	visted[x] = true;
	cout<<x<<' ';
	for(int i=0; i<vec[x].size(); i++)
		dfs(vec[x][i]);
}

void	bfs(int x)
{
	queue<int>	q;
	int		d1, d2;

	visted[x] = true;
	q.push(x);
	while (!q.empty())
	{
		d1 = q.front();
		q.pop();
		cout<<d1<<' ';
		for(int i=0; i<vec[d1].size(); i++)
		{
			d2 = vec[d1][i];
			if (!visted[d2])
			{
				q.push(d2);
				visted[d2] = true;
			}
		}
	}
}

int		main(void)
{
	vec[1].push_back(2);
	vec[1].push_back(3);

	vec[2].push_back(4);
	vec[2].push_back(5);

	vec[3].push_back(6);
	vec[3].push_back(7);

	bfs(1);
	cout<<'\n';
	memset(visted, 0, sizeof(visted));
	dfs(1);
}