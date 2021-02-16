#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define	MAX	32002

vector<int>	vec[MAX];
int		inDegree[MAX];
int		ans[MAX];
int		n, m, p1, p2;

void	topologySort(void)
{
	priority_queue<int>	pq;
	int		idx=0;

	for(int i=1; i<=n; i++)
		if (!inDegree[i])
			pq.push(-i);
	while (!pq.empty())
	{
		p1 = -pq.top();
		pq.pop();
		ans[++idx] = p1;
		for(int i=0; i<vec[p1].size(); i++)
		{
			p2 = vec[p1][i];
			if (!(--inDegree[p2]))
				pq.push(-p2);
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	memset(inDegree, 0, sizeof(inDegree));
	for(int i=0; i<m; i++)
	{
		cin>>p1>>p2;
		vec[p1].push_back(p2);
			inDegree[p2]++;
	}
	topologySort();
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<' ';
}