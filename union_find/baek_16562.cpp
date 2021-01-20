#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// <친구부모노드, 친구최소비용>
map<int, int>			f_map;
map<int, int>::iterator	it;
int		cost[10002];
int		parent[10002];
int		n, m, k, m1, m2, p, ans=0;

int		getParent(int m)
{
	if (parent[m] == m)
		return (m);
	parent[m] = getParent(parent[m]);
	return (parent[m]);
}

void	unionParent(int m1, int m2)
{
	m1 = getParent(m1);
	m2 = getParent(m2);
	if(m1 < m2)
		swap(m1, m2);
	parent[m1] = m2;
}

int		main(void)
{
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		parent[i] = i;
	for(int i=1; i<=n; i++)
		cin>>cost[i];
	for(int i=0; i<m; i++)
	{
		cin>>m1>>m2;
		unionParent(m1, m2);  // 친구면 합치기
	}
	for(int i=1; i<=n; i++)
	{
		p = getParent(i);  // 해당 친구의 부모노드
		if (!f_map.count(p))  // 해당 해쉬맵의 인덱스가 비어있으면 
			f_map[p] = cost[i];  // 친구비용 넣기
		else
			// 해당 해쉬맵의 인덱스가 비어있지 않으면 친구비용을 더작은값으로 변경
			f_map[p] = min(f_map[p], cost[i]);
	}
	for(it=f_map.begin(); it!=f_map.end(); it++)
		ans += it->second;  // 해쉬맵에 있는 친구비용 모두 더하기
	if (k < ans)  // 친구최소비용이 가진돈보다 많으면
		cout<<"Oh no";
	else
		cout<<ans;
}