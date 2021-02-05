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
long long	ans=0;
int			parent[1002];
int			arr[1002][1002];
int			n;

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
		parent[i] = i;
		for(int j=0; j<n; j++)
		{
			cin>>arr[i][j];
			if (i < j)
				vec.push_back(Edge(i, j, arr[i][j]));
		}
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