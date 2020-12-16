#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define	INF	987654321

vector< pair<long long, pair<long long, long long> > >	edge1;  // 교통비만
vector< pair<long long, pair<long long, long long> > >	edge2;  // 교통비 + 수입
bool		visit[102];  // 출발지에서 도착지로 갈때 들릴수 있는 모든곳 체크
long long	income[102];  // 수입
long long	money[102];  // 가지고 있는돈
long long	n, m, src, dest, from, to, weight;

void	bellman_ford(long long start)
{
	memset(visit, 0, sizeof(visit));  // 방문 초기화
	for(int i=0; i<n; i++)
		money[i] = -INF;  // 매우 작은값으로 가지고있는돈 초기화
	money[start] = income[start];  // 초기값 : 출발도시 에서의 수입
	visit[dest] = true;  // 도착도시 방문
	for(int i=0; i<=n; i++)
		for(int j=0; j<edge2.size(); j++)
		{
			from = edge2[j].second.first;
			to = edge2[j].second.second;
			weight = edge2[j].first;
			if (visit[to] == true)  // 도착지점이 방문한곳이면
				visit[from] = true;  // 출발지점도 방문
			if (money[from]!=-INF && money[to]<money[from]+weight)
			{
				money[to] = money[from]+weight;
				// 충분히 반복이 된경우
				// 도착도시에 도착할수 있는 경우
				// 출발도시에서 도착도시로가는 모든경로중 양의 순환구조가 존재하는 경우
				if (i==n && money[dest]!=-INF && visit[to])
				{
					cout<<"Gee"<<'\n';
					exit(0);
				}
			}
		}
}

int		main(void)
{
	cin>>n>>src>>dest>>m;
	for(int i=0; i<m; i++)
	{
		cin>>from>>to>>weight;
		edge1.push_back(make_pair(-weight, make_pair(from, to)));  // 교통비 입력
	}
	for(int i=0; i<n; i++)
		cin>>income[i];  // 도시에서 버는 돈
	for(int i=0; i<m; i++)
	{
		from = edge1[i].second.first;
		to = edge1[i].second.second;
		weight = edge1[i].first+income[to];
		// 교통비 + 도시에서 버는돈
		edge2.push_back(make_pair(weight, make_pair(from, to)));
	}
	bellman_ford(src);
	if (money[dest] == -INF)  // 도착할수 없을때
		cout<<"gg"<<'\n';
	else
		cout<<money[dest]<<'\n';
}