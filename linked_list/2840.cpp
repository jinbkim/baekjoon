#include <iostream>
#include <list>
#include <iterator>
#include <cstring>
using namespace std;

bool	flag=0;
char	visit[256];
char	w;
int		n, k, s;

int		main(void)
{
	cin>>n>>k;

	list<char>				lt(n, '?');  // ?값을 가지는 n개 노드를 가진 리스트 만들기
	list<char>::iterator	it;

	memset(visit, 0, sizeof(visit));
	it = lt.begin();
	for(int i=0; i<k; i++)
	{
		cin>>s>>w;
		for(int j=0; j<s; j++)
			if (++it == lt.end())  // iterator 노드가 맨끝으로 오면
				it = lt.begin();  // 맨앞으로 
		if (*it == '?')  // 아직 입력되지 않은 자리면
		{
			*it = w;
			if (visit[w])  // 이미 사용한 알파벳이면
				flag = 1;
		}
		else if (*it != w)  // 입력된곳인데 다른 알파벳이 입력으로 들어왔다면
			flag = 1;
		visit[w] = 1;  // 사용한 알파벳 방문처리
	}
	if (flag)
		cout<<"!";
	else
		for(int i=0; i<n; i++)
		{
			cout<<*it;
			if (it == lt.begin())
				it = lt.end();
			--it;
		}
}