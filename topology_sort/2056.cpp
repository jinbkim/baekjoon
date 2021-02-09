#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define	MAX	10002

vector<int>	vec[MAX];
int		inDegree[MAX];
int		dp[MAX];
int		t[MAX];
int		n, m, node1, node2;

void	topologySort(void)
{
	queue<int>	q;
	int		time;

	for(int i=1; i<=n; i++)
		if (!inDegree[i])
			q.push(i);
	while (!q.empty())
	{
		node1 = q.front();
		q.pop();
		for(int j=0; j<vec[node1].size(); j++)
		{
			node2 = vec[node1][j];
			dp[node2] = max(dp[node2], t[node2]+dp[node1]);
			if (!(--inDegree[node2]))
				q.push(node2);
		}
	}
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n;
	memset(inDegree, 0, sizeof(inDegree));
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++)
	{
		cin>>t[i]>>m;
		dp[i] = t[i];
		for(int j=0; j<m; j++)
		{
			cin>>node1;
			vec[node1].push_back(i);
			inDegree[i]++;
		}
	}
	topologySort();
	sort(dp, dp+n+1);
	cout<<dp[n];
}