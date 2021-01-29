#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class	Edge
{
public:
	int	x, y, e;

	Edge(int x, int y, int e) : x(x), y(y), e(e) {}

	bool	operator<(const Edge &edge) const
	{
		return(this->e < edge.e);
	}
};

int		parent[200002];
int		n, m, x, y, z, sum1, sum2;

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

	while (true)
	{
		vector<Edge>	vec;  // 벡터의 초기화를 위해 전역변수가 아닌 지역변수로 선언

		cin>>m>>n;
		if (!m && !n)
			break ;
		sum1 = 0;
		for(int i=0; i<n; i++)
		{
			parent[i] = i;
			cin>>x>>y>>z;
			vec.push_back(Edge(x, y, z));
			sum1 += z;
		}
		sort(vec.begin(), vec.end());
		sum2 = 0;
		for(int i=0; i<n; i++)
			if (!sameParent(vec[i].x, vec[i].y))
			{
				sum2 += vec[i].e;
				unionParent(vec[i].x, vec[i].y);
			}
		cout<<sum1-sum2<<'\n';
	}
}