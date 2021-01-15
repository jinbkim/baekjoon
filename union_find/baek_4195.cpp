#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
#define	MAX	200002

string	str1, str2;
int		parent[MAX];
int		ans[MAX];
int		n, f, p1, p2, m_i;

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
	if (n2 < n1)
		swap(n1, n2);
	parent[n2] = n1;
	ans[n1] += ans[n2];  // 부모노드에 정답 몰아주기 
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		map<string, int>	m;

		cin>>f;
		// 초기화
		for(int j=0; j<MAX; j++)
		{
			parent[j] = j;
			ans[j] = 1;
		}
		for(int j=0; j<f; j++)
		{
			cin>>str1>>str2;
			if (!m.count(str1))  // 새로운 입력값이 들어오면
				m[str1] = ++m_i;  // 해쉬 맵에 새로운 인덱스 부여
			if (!m.count(str2))  // 새로운 입력값이 들어오면
				m[str2] = ++m_i;  // 해쉬 맵에 새로운 인덱스 부여
			p1 = getParent(m[str1]);  // 부모노드 찾기
			p2 = getParent(m[str2]);  // 부모노드 찾기
			if (p1 != p2)  // 부모 노드가 다르다는건 합집합이 아니라는 뜻
				unionParent(m[str1], m[str2]);  // 합치기
			cout<<max(ans[p1], ans[p2])<<'\n';  // 정답 출력
		}
	}
}