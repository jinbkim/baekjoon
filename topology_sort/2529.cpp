#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define	MAX	11

vector<int>	max_v[MAX];
vector<int>	min_v[MAX];
char	c;
char	arr[MAX];
int		maxInDegree[MAX];
int		minInDegree[MAX];
int		ans1[MAX];
int		ans2[MAX];
int		k;

void	topologySort1(void)
{
	priority_queue<int>	q;
	int		n1, n2;

	for(int i=0; i<=k; i++)
		if (!maxInDegree[i])
			q.push(i);
	for(int i=0; i<=k; i++)
	{
		n1 = q.top();
		q.pop();
		ans1[n1] = i;
		for(int j=0; j<max_v[n1].size(); j++)
		{
			n2 = max_v[n1][j];
			if (!(--maxInDegree[n2]))
				q.push(n2);
		}
	}
}

void	topologySort2(void)
{
	priority_queue<int>	q;
	int		n1, n2;

	for(int i=0; i<=k; i++)
		if (!minInDegree[i])
			q.push(-i);
	for(int i=0; i<=k; i++)
	{
		n1 = -q.top();
		q.pop();
		ans2[n1] = i;
		for(int j=0; j<min_v[n1].size(); j++)
		{
			n2 = min_v[n1][j];
			if (!(--minInDegree[n2]))
				q.push(-n2);
		}
	}
}

int		main(void)
{
	cin>>k;
	memset(maxInDegree, 0, sizeof(maxInDegree));
	memset(minInDegree, 0, sizeof(minInDegree));
	for(int i=0; i<k; i++)
	{
		cin>>c;
		if (c == '<')
		{
			max_v[i].push_back(i+1);
			min_v[i].push_back(i+1);
			maxInDegree[i+1]++;
			minInDegree[i+1]++;
		}
		else if (c == '>')
		{
			max_v[i+1].push_back(i);
			min_v[i+1].push_back(i);
			maxInDegree[i]++;
			minInDegree[i]++;
		}
	}
	topologySort1();
	topologySort2();
	for(int i=0; i<=k; i++)
		cout<<ans1[i]+9-k;
	cout<<'\n';
	for(int i=0; i<=k; i++)
		cout<<ans2[i];
}