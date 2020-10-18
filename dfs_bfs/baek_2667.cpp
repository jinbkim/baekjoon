#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<int>	vec;
string	map[27];
int		visted[27][27];
int		cnt, n;

void	init(void)
{
	cnt = 0;
	memset(visted, 0, sizeof(visted));
}

void	bfs(int i, int j)
{
	queue< pair <int, int> >	q;
	int		ret;
	
	if (visted[i][j] || map[i][j] == '0')
		return ;
	ret = 0;
	visted[i][j] = true;
	q.push(make_pair(i, j));
	while (!q.empty())
	{
		i = q.front().first;
		j = q.front().second;
		q.pop();
		ret++;
		if (j != n-1 && !visted[i][j+1] && map[i][j+1] == '1')
		{
			q.push(make_pair(i, j+1));
			visted[i][j+1] = true;
		}
		if (j && !visted[i][j-1] && map[i][j-1] == '1')
		{
			q.push(make_pair(i, j-1));
			visted[i][j-1] = true;
		}
		if (i != n-1 && !visted[i+1][j] && map[i+1][j] == '1')
		{
			q.push(make_pair(i+1, j));
			visted[i+1][j] = true;
		}
		if (i && !visted[i-1][j] && map[i-1][j] == '1')
		{
			q.push(make_pair(i-1, j));
			visted[i-1][j] = true;
		}
	}
	cnt++;
	vec.push_back(ret);
}



int		main(void)
{
	init();
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>map[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			bfs(i, j);
	sort(vec.begin(), vec.end());
	cout<<cnt<<'\n';
	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<'\n';
}