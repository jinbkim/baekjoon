#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define	MAX 10002

vector<int>	vec[MAX];
int		inDegree[MAX];
int		dp[MAX];
int		t[MAX];
int		n, m;

void	topologySort(void)
{
	queue<int>	q;
	int		n1, n2;

	for(int i=1; i<=n; i++)
		if (!inDegree[i])
			q.push(i);
	while (!q.empty())
	{
		n1 = q.front();
		q.pop();
		for(int i=0; i<vec[n1].size(); i++)
		{
			n2 = vec[n1][i];
			dp[n2] = max(dp[n2], t[n2]+dp[n1]);
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

	cin>>n;
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++)
	{
		cin>>t[i]>>m;
		dp[i] = t[i];
		for(int j=0, node; j<m; j++)
		{
			cin>>node;
			vec[node].push_back(i);
			inDegree[i]++;
		}
	}
	topologySort();
	sort(dp, dp+n+1);
	cout<<dp[n];
}