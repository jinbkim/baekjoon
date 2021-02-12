#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAX	32002

vector<int>	vec[MAX];
int		inDegree[MAX];
int		ans[MAX];
int		n, m, man1, man2;

void	topologySort(void)
{
	queue<int>	q;
	int		n1, n2, idx=-1;
	for(int i=1; i<=n; i++)
		if (!inDegree[i])
			q.push(i);
	while (!q.empty())
	{
		n1 = q.front();
		q.pop();
		ans[++idx] = n1;
		for(int i=0; i<vec[n1].size(); i++)
		{
			n2 = vec[n1][i];
			if (!(--inDegree[n2]))
				q.push(n2);
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
		cin>>man1>>man2;
		vec[man1].push_back(man2);
		inDegree[man2]++;
	}
	topologySort();
	for(int i=0; i<n; i++)
		cout<<ans[i]<<' ';
}