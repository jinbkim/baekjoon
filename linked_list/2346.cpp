#include <iostream>
#include <list>
using namespace std;

list< pair<int, int> >				l;
list< pair<int, int> >::iterator	base;
list< pair<int, int> >::iterator	it;

int	n, cmd;

int		main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>cmd;
		l.push_back(make_pair(i, cmd));  // (풍선번호, 이동해야하는 규칙)
	}
	base = l.begin();  // 1번풍선부터 시작
	for(int i=1; i<=n; i++)
	{
		if (base == l.end())
			base = l.begin();
		it = base;  // 현재 풍선을 지우기위해서 it에 저장
		cmd = base->second;  // 이동해야하는 규칙
		cout<<base->first<<' ';  // 터트릴 풍선 번호
		if (++base == l.end())  // 시계방향으로 한번이동하고 리스트에 끝이면
			base = l.begin();  // 원모양이므로 풍선의 처음으로 돌아감 
		l.erase(it);  // 풍선 터트리기
		if (l.empty())
			break ;
		if (0 <= cmd)  // 시계방향으로 이동
		{
			for(int j=0; j<cmd-1; j++, base++)
				if (base == l.end())
					base = l.begin();
		}
		else   // 반시계 방향으로 이동
		{
			for(int j=0; j<-cmd; j++, base--)
			{
				if (base == l.begin())
					base = l.end();
			}
		}
	}
}