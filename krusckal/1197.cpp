#include <iostream>
#include <vector>
#include <algorithm>
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

vector<Edge>	vec;
int		parent[10002];
int		vn, en, v1, v2, e, ans=0;

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

	cin>>vn>>en;
	for(int i=0; i<en; i++)
	{
		cin>>v1>>v2>>e;
		vec.push_back(Edge(v1, v2, e));
	}
	sort(vec.begin(), vec.end());
	for(int i=1; i<=vn; i++)
		parent[i] = i;
	for(int i=0; i<en; i++)
		if (!sameParent(vec[i].v1, vec[i].v2))
		{
			ans += vec[i].e;
			unionParent(vec[i].v1, vec[i].v2);
		}
	cout<<ans;
}