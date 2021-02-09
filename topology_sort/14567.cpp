#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int>	vec[1002];
int		ans[1002];
int		inDegree[1002];
int		n, m, subj1, subj2;

void	topologySort(void)
{
	queue< pair<int, int> >	q;
	int		n1, n2, level;
	for(int i=1; i<=n; i++)
		if (!inDegree[i])
			q.push(make_pair(i, 0));
	while (!q.empty())
	{
		n1 = q.front().first;
		level = q.front().second;
		q.pop();
		ans[n1] = level;
		for(int i=0; i<vec[n1].size(); i++)
		{
			n2 = vec[n1][i];
			if (!(--inDegree[n2]))
				q.push(make_pair(n2, level+1));
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
	memset(ans, 0, sizeof(ans));
	for(int i=0; i<m; i++)
	{
		cin>>subj1>>subj2;
		vec[subj1].push_back(subj2);
		inDegree[subj2]++;
	}
	topologySort();
	for(int i=1; i<=n; i++)
		cout<<ans[i]+1<<' ';
}