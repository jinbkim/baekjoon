#include <iostream>
#include <cstring>
using namespace std;

bool	dis[502][502];
int		cnt[502];
int		n, m, from, to, ret=0;

void	floyd_warshal(void)
{
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				if (dis[j][i] && dis[i][k])  // j,i와 i,k의 대소관계를 알면
					dis[j][k] = true;  // j와 k의 대소관계도 암
}

int		main(void)
{
	cin>>n>>m;
	memset(cnt, 0, sizeof(cnt));
	memset(dis, 0, sizeof(dis));
	for(int i=0; i<m; i++)
	{
		cin>>from>>to;
		dis[from][to] = true;  // from과 to의 대소관계를 암
	}
	floyd_warshal();
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if (dis[i][j])  // i와 j의 대소관계를 알면
			{
				cnt[i]++;  // 배열의 i번째 인덱스값 1증가
				cnt[j]++;  // 배열의 j번째 인덱스 1증가
			}
		}
	for(int i=1; i<=n; i++)
		if (cnt[i] == n-1)  // 다른 모든 학생들과 대소관계를 알고 있다면
			ret++;
	cout<<ret<<'\n';
}