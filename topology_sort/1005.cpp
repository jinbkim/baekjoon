#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 1002

int		inDegree[MAX];
int		build[MAX];
int		dp[MAX];
int		t, n, k, b1, b2, last;

void	topologySort(vector <int> vec[])
{
	queue<int>	q;
	int		n1, n2;

	for(int i=1; i<=n; i++)
		if(!inDegree[i])
			q.push(i);
	while (!q.empty())
	{
		n1 = q.front();
		q.pop();
		for(int i=0; i<vec[n1].size(); i++)
		{
			n2 = vec[n1][i];
			dp[n2] = max(dp[n2], dp[n1]+build[n2]);
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

	cin>>t;
	for(int i=0; i<t; i++)
	{
		vector<int>	vec[MAX];

		memset(inDegree, 0, sizeof(inDegree));
		cin>>n>>k;
		for(int i=1; i<=n; i++)
		{
			cin>>build[i];
			dp[i] = build[i];
		}
		for(int i=0; i<k; i++)
		{
			cin>>b1>>b2;
			vec[b1].push_back(b2);
			inDegree[b2]++;
		}
		cin>>last;
		topologySort(vec);
		cout<<dp[last]<<'\n';
	}
}