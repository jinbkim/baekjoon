#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <iterator>
#include <algorithm>
using namespace std;
#define MAX	502

vector<int>				rankChange[MAX];
vector<int>				adj[MAX];
vector<int>::iterator	it;
int	t, n, m, t1, t2;
int	ranking[MAX];
int	ans[MAX];

void	rankChanging(void)
{
	int	visit[MAX];

	for(int i=1; i<=n; i++)
		for(int j=0; j<rankChange[i].size(); i++)
		{
			t1 = i;
			t2 = rankChange[i][j];
			// cout<<"t1 : "<<t1<<", t2 : "<<t2<<'\n';
			for(it=adj[t2].begin(); it!=adj[t2].end(); it++)
				if (*it == t1)
					adj[t2].erase(it);
			adj[t1].push_back(t2);
		}
	memset(visit, 0, sizeof(visit));
	for(int i=1; i<=n; i++)
	{
		visit[adj[i].size()]++;
		if (1 < visit[adj[i].size()])
		{
			cout<<"IMPOSSIBLE\n";
			return ;
		}
	}
	for(int i=1; i<=n; i++)
		ans[n-adj[i].size()] = i;
	for(int i=1; i<=n; i++)
		cout<<ans[i]<<' ';
	cout<<'\n';
}

int		main(void)
{
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		for(int j=0; j<n; j++)
			cin>>ranking[j];
		for(int j=0; j<n; j++)
			for(int k=j+1; k<n; k++)
				adj[ranking[j]].push_back(ranking[k]);
		cin>>m;
		for(int j=0; j<m; j++)
		{
			cin>>t1>>t2;
			for(int k=0; k<adj[t1].size(); k++)
				if (adj[t1][k] == t2)
					swap(t1, t2);
			// cout<<"t1 : "<<t1<<", t2 : "<<t2<<'\n';
			rankChange[t1].push_back(t2);
		}
		rankChanging();
		for(int i=0; i<=n; i++)
		{
			adj[i].clear();
			rankChange[i].clear();
		}
	}
}