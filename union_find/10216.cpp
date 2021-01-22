#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int		parent[3002];
bool	visit[3002];
int		t, n, x, y, r, ans;

// 같은 구역이면 true 아니면 false 반환
bool	is_overlap(int x1, int y1, int r1, int x2, int y2, int r2)
{
	if (pow(x1-x2,2) + pow(y1-y2,2) <= pow(r1+r2,2))
		return (true);
	else
		return (false);
}

int		getParent(int a)
{
	if (parent[a] == a)
		return (a);
	parent[a] = getParent(parent[a]);
	return(parent[a]);
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

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>t;
	for(int i=0; i<t; i++)
	{
		vector< pair< pair<int, int>, int> >	v;
		cin>>n;
		for(int j=0; j<n; j++)
		{
			parent[j] = j;
			cin>>x>>y>>r;
			v.push_back(make_pair(make_pair(x, y), r));
			for(int k=0; k<j; k++)
				// 같은 구역이면
				if (is_overlap(v[k].first.first, v[k].first.second, v[k].second, x, y, r))
					unionParent(k, j);
		}
		memset(visit, 0, sizeof(visit));
		ans = 0;
		for(int j=0; j<n; j++)
		{
			parent[j] = getParent(j);
			if (!visit[parent[j]])
			{
				visit[parent[j]] = true;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
}