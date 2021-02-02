#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class	Edge
{
public:
	int i, j, e;

	Edge(int i, int j, int e) : i(i), j(j), e(e) {}

	bool	operator<(const Edge &edge) const
	{
		return (this->e < edge.e);
	}
};

class	Vertex
{
public:
	int x, y, z, idx;  // idx : 정점의 인덱스
};     

vector<Edge>	vec;
Vertex	ver[100002];
int		parent[100002];
long long		n, ans=0;

bool	compX(Vertex &v1, Vertex &v2)
{
	return (v1.x < v2.x);
}

bool	compY(Vertex &v1, Vertex &v2)
{
	return (v1.y < v2.y);
}

bool	compZ(Vertex &v1, Vertex &v2)
{
	return (v1.z < v2.z);
}

int		getDis(int i, int j)
{
	return (min(min(abs(ver[i].x-ver[j].x), abs(ver[i].y-ver[j].y)), abs(ver[i].z-ver[j].z)));
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

	cin>>n;
	for(int i=0; i<n; i++)
	{
		parent[i] = i;  // 부모노드 초기화
		cin>>ver[i].x>>ver[i].y>>ver[i].z;
		ver[i].idx = i;  // 정점의 인덱스 설정
	}

	// x좌표를 오름차순으로 정점 정렬
	sort(ver, ver+n, compX);
	for(int i=1; i<n; i++)
		// 정렬된 정점들중 연속된 2개의 정점을 벡터안에 넣기
		vec.push_back(Edge(ver[i-1].idx, ver[i].idx, getDis(i, i-1)));
	// y좌표를 오름차순으로 정점 정렬
	sort(ver, ver+n, compY);
	for(int i=1; i<n; i++)
		// 정렬된 정점들중 연속된 2개의 정점을 벡터안에 넣기
		vec.push_back(Edge(ver[i-1].idx, ver[i].idx, getDis(i, i-1)));
	// z좌표를 오름차순으로 정점 정렬
	sort(ver, ver+n, compZ);
	for(int i=1; i<n; i++)
		// 정렬된 정점들중 연속된 2개의 정점을 벡터안에 넣기
		vec.push_back(Edge(ver[i-1].idx, ver[i].idx, getDis(i, i-1)));
	
	// 간선의 거리순으로 벡터 정렬
	sort(vec.begin(), vec.end());
	for(int i=0; i<vec.size(); i++)
	{
		if (!sameParent(vec[i].i, vec[i].j))
		{
			ans += vec[i].e;
			unionParent(vec[i].i, vec[i].j);
		}
	}
	cout<<ans;
}