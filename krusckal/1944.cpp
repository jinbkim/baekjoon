#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

class	Edge
{
public:
	int	v1, v2, e;
	
	Edge(int v1, int v2, int e) : v1(v1), v2(v2), e(e) {}

	bool operator<(const Edge &edge) const
	{
		return (this->e < edge.e);
	}
};

class	Vertax
{
public:
	int	x, y;

	Vertax() {}
	Vertax(int x, int y) : x(x), y(y) {}
};

vector<Edge>	vec;
Vertax	ver[252];
int		parent[252];
char	maze[52][52];
int		dx[4] = {-1,1,0,0};
int		dy[4] = {0,0,-1,1};
int		n, m, ver_i=-1, ans=0;

int		getDis(int i, int j)
{
	queue <pair<Vertax, int> >	q;
	bool	visit[52][52];  // 재방문 방지를 위해 방문체크
	int	x = ver[i].x;
	int	y = ver[i].y;
	int d, nx, ny;

	memset(visit, 0, sizeof(visit));
	q.push(make_pair(Vertax(x, y), 0));
	visit[y][x] = 1;
	while (!q.empty())
	{
		x = q.front().first.x;
		y = q.front().first.y;
		d = q.front().second;
		q.pop();
		if (x==ver[j].x && y==ver[j].y)
			return (d);
		for(int i=0; i<4; i++)
		{
			nx = x+dx[i];
			ny = y+dy[i];
			if (0<=nx && nx<n && 0<=ny && ny<n && maze[ny][nx]!='1' && !visit[ny][nx])
			{
				q.push(make_pair(Vertax(nx, ny), d+1));
				visit[ny][nx] = 1;
			}
		}
	}
	cout<<-1<<'\n';  // 해당 좌표를 못찾으면 종료
	exit(0);
}

int		getParent(int a)
{
	if (parent[a] == a)
		return (a);
	return (parent[a] = getParent(parent[a]));
}

bool	sameParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return (true);
	else
		return (false);
}

void	unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		swap(a, b);
	parent[a] = b;
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>maze[i][j];
			if (maze[i][j]=='S' || maze[i][j]=='K')
			{
				ver[++ver_i].y = i;
				ver[ver_i].x = j;
			}
		}
	for(int i=0; i<=ver_i; i++)
	{
		parent[i] = i;
		for(int j=0; j<i; j++)
			vec.push_back(Edge(i, j, getDis(i, j)));
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<vec.size(); i++)
		if (!sameParent(vec[i].v1, vec[i].v2))
		{
			ans += vec[i].e;
			unionParent(vec[i].v1, vec[i].v2);
		}
	cout<<ans;
}