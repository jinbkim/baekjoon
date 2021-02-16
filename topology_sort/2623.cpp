#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define	MAX 1002

vector<int>	vec[MAX];
int		inDegree[MAX];
int		order[102];
int		ans[MAX];
int		n, m, l, s1, s2;

bool	topologySort(void)
{
	queue<int>	q;
	int		idx=0;
	
	for(int i=1; i<=n; i++)
		if (!inDegree[i])
			q.push(i);
	while(!q.empty())
	{
		s1 = q.front();
		q.pop();
		ans[++idx] = s1;
		for(int i=0; i<vec[s1].size(); i++)
		{
			s2 = vec[s1][i];
			if (!--(inDegree[s2]))
				q.push(s2);
		}
	}
	if (idx != n)  // 모든 가수가 큐에 들어가지 않다는건 사이클이 존재한것
		return (false);
	return (true);
}

int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>l;
		for(int j=0; j<l; j++)
		{
			cin>>order[j];
			if (j)
			{
				vec[order[j-1]].push_back(order[j]);
				inDegree[order[j]]++;
			}
		}
	}
	if (topologySort())  // 그래프 내에 사이클이 없으면
		for(int i=1; i<=n; i++)
			cout<<ans[i]<<'\n';
	else  // 그래프 내에 사이클이 있으면
		cout<<'0';
}