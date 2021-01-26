#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int>	v[1002];
int		parent[1002];
int		p[4];
int		n, ans=0;
bool	visit[1002];

bool	is_overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (x1<x3 && x4<x2 && y1<y3 && y4<y2)  // 사각형이 안에 포함되는 경우1
		return (false);
	else if (x3<x1 && x2<x4 && y3<y1 && y2<y4)  // 사각형이 안에 포함되는 경우2
		return (false);
	else if (x2<x3 || y2<y3 || x4<x1 || y4<y1)  // 사각형이 겹치지 않는경우
		return (false);
	return (true);
}

int		getParent(int n)
{
	if (parent[n] == n)
		return (n);
	return(parent[n] = getParent(parent[n]));
}

void	unionParent(int i, int j)
{
	i = getParent(i);
	j = getParent(j);
	if (i < j)
		swap(i, j);
	parent[i] = j;
}

int		main(void)
{
	cin>>n;
	parent[0] = 0;
	for(int i=0; i<4; i++)
		v[0].push_back(0);  // 거북이가 원점에서 출발하기때문에 일단 원점을 추가함
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		for(int j=0; j<4; j++)
		{
			cin>>p[j];
			v[i].push_back(p[j]);
		}
	}
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			// 사각형이 겹치면
			if (is_overlap(v[i][0], v[i][1], v[i][2],v[i][3],v[j][0],v[j][1],v[j][2],v[j][3]))
				unionParent(i, j);  // 합치기
	memset(visit, 0, sizeof(visit));
	for(int i=0; i<=n; i++)
		if (!visit[getParent(i)] && ++ans)
			visit[getParent(i)] = 1;
	cout<<ans-1;// 거북이가 원점에서 출발하기때문에 일단 원점을 추가해서 1을 빼야함
}