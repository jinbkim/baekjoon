#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int		visit[502];
int		parent[502];
int		edge[502];
int		n, m, v1, v2, ans, cnt=0;

int		getParent(int a)
{
	if (parent[a] == a)
		return (a);
	parent[a] = getParent(parent[a]);
	return (parent[a]);
}

void	unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		swap(a, b);
	parent[a] = b;
	edge[b] += edge[a];  // 인덱스가 작은쪽에 간선의 개수 몰아주기
	edge[b]++;  // 합칠때마다 간선개수 증가
	edge[a] = 0; // 몰아줬으니까 인덱스가 큰쪽은 0으로 만들기
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while (++cnt)
	{
		memset(edge, 0, sizeof(edge));
		cin>>n>>m;
		if (!n && !m)
			break ;
		for(int i=1; i<=n; i++)
			parent[i] = i;
		for(int i=0; i<m; i++)
		{
			cin>>v1>>v2;
			unionParent(v1, v2);
		}
		memset(visit, 0, sizeof(visit));
		for(int i=1; i<=n; i++)
		{
			parent[i] = getParent(i);
			visit[parent[i]]++;  // 부모노드의 방문횟수 세기
		}
		ans = 0;
		for(int i=1; i<=n; i++)
			// 트리의 조건 : 정점의 개수가 n이면 간선의 개수는 n-1
			if (visit[i] == edge[i]+1)
				ans++;
		cout<<"Case "<<cnt<<": ";
		if (!ans)
			cout<<"No trees.\n";
		else if (ans == 1)
			cout<<"There is one tree.\n";
		else
			cout<<"A forest of "<<ans<<" trees.\n";
	}
}