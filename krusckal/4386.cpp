#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int		parent[102];
int		n, cnt=0;
double	p[102][2];
double	ans=0;

class	Edge
{
public:
	int		i, j;
	double	e;

	Edge(int i, int j) : i(i), j(j)
	{
		e = sqrt(pow(p[i][0]-p[j][0],2) + pow(p[i][1]-p[j][1],2));
	}

	bool	operator<(const Edge &edge) const
	{
		return (this->e < edge.e);
	}
};

vector<Edge>	vec;

int		getParent(int i)
{
	if (parent[i] == i)
		return (i);
	return (parent[i] = getParent(parent[i]));
}

bool	sameParent(int i, int j)
{
	i = getParent(i);
	j = getParent(j);
	if (i == j)
		return (true);
	else
		return (false);
}

void	unionParent(int i, int j)
{
	i = getParent(i);
	j = getParent(j);
	if (i < j)
		swap(i, j);
	parent[i] =j ;	
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>p[i][0]>>p[i][1];
		parent[i] = i;
		for(int j=0; j<i; j++)
			vec.push_back(Edge(i, j));  // 모든 간선을 벡터에 넣음
	}
	sort(vec.begin(), vec.end());  // 간선을 오름차순으로 정렬
	for(int i=0; cnt!=n-1; i++)
		if (!sameParent(vec[i].i, vec[i].j) && ++cnt)
		{
			ans += vec[i].e;
			unionParent(vec[i].i, vec[i].j);
		}
	cout<<fixed;  // 소수점을 고정시켜 표현
	cout.precision(2);  // 소수점을 2자리 까지 표현
	cout<<ans;
}