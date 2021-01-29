#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class	Edge
{
public:
	int	i, j, e;

	Edge(int i, int j, int e) : i(i), j(j), e(e) {}
	bool	operator<(const Edge &edge) const
	{
		return (this->e < edge.e);
	}
};

vector<Edge>	vec;
bool	country[12][12];
int		dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int		landMap[12][12];
int		parent[102];
int		n, m, landNum=0, ny, nx, bridgeCnt=0, ans=0;

// 해당 좌표가 범위안에 있는지 체크하는 함수 
bool	inRange(int y, int x)
{
	if (0<=y && y<n && 0<=x && x<m)
		return (true);
	else
		return (false);
}

void	dfs(int y, int x)
{
	landMap[y][x] = landNum;  // 맵에 노드번호 부여
	for(int i=0; i<4; i++)
	{
		ny = y+dir[i][0];
		nx = x+dir[i][1];
		// 해당좌표가 범위안에 있고, 육지이며, 방문한적이 있으면
		if (inRange(ny, nx) && country[ny][nx] && !landMap[ny][nx])
			dfs(ny, nx);  // dfs로 탐색
	}
}

// 가로방향인 다리를 백터에 추가
void	BridgeRow(int i, int j)
{
	int len = 0;  // 다리의 길이
	
	// 가로방향(오른쪽) 으로 육지를 만날때까지 또는 맵의 범위를 벗어나지 않을때까지 반복
	while (!landMap[i][j+len] && j+len<m)
		len++;
	if (len<2 || j+len==m)  // 다리의 길이가 2미만이거나 맵의 범위를 벗어낫거나
		return ;
	// 가로방향 다리의 육지1, 육지2, 길이 정보를 벡터안에 넣기
	vec.push_back(Edge(landMap[i][j-1], landMap[i][j+len], len));
}

// 세로방향인 다리를 백터에 추가
void	BridgeCol(int i, int j)
{
	int len = 0;  // 다리의 길이

	// 세로방향(아래쪽) 으로 육지를 만날때까지 또는 맵의 범위를 벗어나지 않을때까지 반복
	while (!landMap[i+len][j] && i+len<n)
		len++;
	if (len<2 || i+len==n)  // 다리의 길이가 2미만이거나 맵의 범위를 벗어낫거나
		return ;
	// 세로방향 다리의 육지1, 육지2, 길이 정보를 벡터안에 넣기
	vec.push_back(Edge(landMap[i-1][j], landMap[i+len][j], len));
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
	
	cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>country[i][j];
	memset(landMap, 0, sizeof(landMap));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			// 육지이며 방문한적이 없을때, ++landNum로 육지번호 증가
			if (country[i][j] && !landMap[i][j] && ++landNum)
				dfs(i, j);

	for(int i=1; i<=landNum; i++)
		parent[i] = i;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			// 육지일때
			if(landMap[i][j])
			{
				// 바로 아래가 범위안이며, 물일때
				if (inRange(i+1, j) && !landMap[i+1][j])
					BridgeCol(i+1, j);  // 아래로 다리 놓기 
				// 바로 오른쪽이 범위안이며, 물일때
				if (inRange(i, j+1) && !landMap[i][j+1])
					BridgeRow(i, j+1);  // 오른쪽으로 다리 놓기
			}
	// 다리길이를 오름차순으로 정렬
	sort(vec.begin(), vec.end());

	// 다리의개수 == 섬의개수-1 이거나 다리를 모두 사용할때까지 반복
	for(int i=0; i<vec.size() && bridgeCnt!=landNum-1; i++)
		// 육지의 부모노드가 같으면 = 다리로 이어져있으면, ++bridgeCnt로 다리개수 새기
		if (!sameParent(vec[i].i, vec[i].j) && ++bridgeCnt)
		{
			ans += vec[i].e;
			// 다리로 육지 잇기
			unionParent(vec[i].i, vec[i].j);
		}
	// 다리의개수 == 섬의개수-1 가 아니면
	if (bridgeCnt != landNum-1)
		ans = -1;
	cout<<ans;
}