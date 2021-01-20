#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

queue< pair<int, int> >		q_water, q_ice;
vector< pair<int, int> >	swan;
char	lake[1502][1502];
int		child[1502][1502];
int		parent[1502*1502];
int		dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int		r, c, cnt=0, ret=-1;

int		getParent(int n)
{
	if (parent[n] == n)
		return (n);
	parent[n] = getParent(parent[n]);
	return (parent[n]);
}

void	unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return ;
	if (a < b)
		swap(a, b);
	parent[a] = b;
}

void	bfs_merge(void)
{
	int	x, y, nx, ny;

	while (!q_water.empty())
	{
		y = q_water.front().first;
		x = q_water.front().second;
		q_water.pop();
		// 받은 데이터전부 녹이는 큐로 넘기기
		q_ice.push(make_pair(y, x));
		for(int i=0; i<4; i++)
		{
			ny = y+dir[i][0];
			nx = x+dir[i][1];
			if (0<=ny && ny<r && 0<=nx && nx<c)
				if (child[ny][nx])  // 물공간 일때
					unionParent(child[ny][nx], child[y][x]);
		}
	}	
}

void	bfs_melt(void)
{
	int x, y, nx, ny;

	while (!q_ice.empty())
	{
		y = q_ice.front().first;
		x = q_ice.front().second;
		q_ice.pop();
		for(int i=0; i<4; i++)
		{
			ny = y+dir[i][0];
			nx = x+dir[i][1];
			if (0<=ny && ny<r && 0<=nx && nx<c)
				if (!child[ny][nx])  // 얼음공간 일때
				{
					// 얼음공간을 물공간으로 바꾸기
					child[ny][nx] = child[y][x];
					// 바뀐부분 데이터만 합치는 큐로 넘기기
					q_water.push(make_pair(ny, nx));
				}
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	memset(child, 0, sizeof(child));
	cin>>r>>c;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			cin>>lake[i][j];
			if (lake[i][j] != 'X')
			{
				if (lake[i][j] == 'L')
					swan.push_back(make_pair(i, j));
				child[i][j] = ++cnt;  // 데이터에 노드 번호 부여 
				parent[cnt] = cnt;  // 부모노드 초기화
				q_water.push(make_pair(i, j));  // 합치는 큐에 데이터 넣기
			}
		}
	while (++ret || true)
	{
		bfs_merge();  // 물공간 합치기
		// 백조가 만날수 있다면
		if (getParent(child[swan[0].first][swan[0].second]) == getParent(child[swan[1].first][swan[1].second]))
			break ;
		bfs_melt();  // 물에 맞닿는 얼음공간 녹이기
	}
	cout<<ret;
}