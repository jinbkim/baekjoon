#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class	Edge
{
public:
	int		v1, v2;
	double	e;
	
	Edge(int v1, int v2, double e) : v1(v1), v2(v2), e(e) {}

	bool operator<(const Edge &edge) const
	{
		return (this->e < edge.e);
	}
};

vector<Edge>	vec;
double	ans=0;
int		parent[1002];
int		x[1002];
int		y[1002];
int		n, m, a, b;

int		getParent(int a)
{
	if (parent[a] == a)
		return (a);
	return (parent[a] = getParent(parent[a]));
}

void	unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		swap(a, b);
	parent[a] = b;
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

double	getDis(int a, int b)
{
	return (sqrt(pow(x[a]-x[b],2) + pow(y[a]-y[b],2)));
}

int		main(void)
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		cin>>x[i]>>y[i];
		for(int j=1; j<i; j++)
			// 모든 통로를 벡터에 넣기
			vec.push_back(Edge(i, j, getDis(i, j)));
	}
	for(int i=0; i<m; i++)
	{
		cin>>a>>b;
		unionParent(a, b);
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<vec.size(); i++)
		if (!sameParent(vec[i].v1, vec[i].v2))
		{
			ans += vec[i].e;
			unionParent(vec[i].v1, vec[i].v2);
		}
	cout<<fixed;  // 소수점을 고정시켜 표현
	cout.precision(2);  // 소수점 2자리까지 표현
	cout<<ans;
}