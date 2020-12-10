#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool	visit[302][302];
int		dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};  // 나이트의 이동방향
int		from[2], to[2];
int		t, l;

int		bfs(void)
{
	queue< pair<pair<int, int>, int> >	q;
	int		cur[2], next[2];
	int		ret=0;

	q.push(make_pair(make_pair(from[0], from[1]), 0));
	while(1)
	{
		cur[0] = q.front().first.first;
		cur[1] = q.front().first.second;
		ret = q.front().second;  // 이동거리
		if (cur[0]==to[0] && cur[1]==to[1])
			return (ret);
		q.pop();
		for(int i=0; i<8; i++)
		{
			next[0] = cur[0]+dir[i][0];
			next[1] = cur[1]+dir[i][1];
			// 나이트가 체스판의 크기를 넘지 않아야하고, 방문한 지점이 아닐때
			if (0<=next[0] && next[0]<l && 0<=next[1] && next[1]<l && !visit[next[0]][next[1]])
			{
				visit[next[0]][next[1]] = true;  // 방문체크
				q.push(make_pair(make_pair(next[0], next[1]), ret+1));
			}
		}
	}
	return (ret);
}

int		main(void)
{
	cin>>t;
	for(int i=0; i<t; i++)
	{
		memset(visit, 0, sizeof(visit));  // 방문 초기화
		cin>>l>>from[0]>>from[1]>>to[0]>>to[1];
		cout<<bfs()<<'\n';
	}
}