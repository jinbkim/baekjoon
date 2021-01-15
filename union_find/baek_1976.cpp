#include <iostream>
using namespace std;

int		parent[202];

int		getParent(int n)
{
	if (parent[n] == n)
		return (n);
	parent[n] = getParent(parent[n]);
	return (parent[n]);
}

void	unionParent(int n1, int n2)
{
	n1 = getParent(n1);
	n2 = getParent(n2);
	if (n1 < n2)
		parent[n2] = n1;
	else
		parent[n1] = n2;
}

int		main(void)
{
	bool	flag;
	int		n, m, city, firstParent;

	cin>>n>>m;
	for(int i=1; i<=n; i++)
		parent[i] = i;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			cin>>city;
			if (city)  // 도시간 경로가 존재하면
				unionParent(i, j);  // 합집합으로 묶기
		}
	cin>>city;
	firstParent = getParent(city);  // 첫번째 경로의 부모노드 구하기
	flag = true;  // 경로가 있는지 없는지 확인하는 플래그
	for(int i=1; i<m; i++)
	{
		cin>>city;
		city = getParent(city);  // 부모노드 구하기
		if (city != firstParent)  // 구한 부모노드가 첫번째 경로의 부모노드와 다르면
		{
			flag = false;  // 합집합이 아님
			break ;
		}
	}
	if (flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}