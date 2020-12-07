#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool	hansu[1002];  // 한수이면 true, 아니면 false
int		visit[1002];  // memoization
int		n;

bool	is_hansu(int val)  // val이 한수이면 true, 아니면 false를 반환하는 함수
{
	string	str;
	int		diff1, diff2;

	str = to_string(val);
	for(int i=0; i<str.size()-2; i++)
	{
		diff1 = str[i+1]-str[i];
		diff2 = str[i+2]-str[i+1];
		if (diff1 != diff2)
			return (false);
	}
	return (true);
}

void	init(void)
{
	memset(visit, 0, sizeof(visit));
	memset(hansu, 0, sizeof(hansu));
	for(int i=1; i<100; i++)  // 99이하의 입력값의 출력값은 입력값과 같음
		visit[i] = i;
	for(int i=100; i<=n; i++)  // 한수이면 true, 아니면 false
		if (is_hansu(i))
			hansu[i] = true;
}

int		brute_force(int val)
{
	if (visit[val])  // 기저사례
		return (visit[val]);  // memoization
	if (!visit[val-1])  // 재귀호출로 쪼개기
		visit[val-1] = brute_force(val-1);
	if (visit[val-1])
	{
		if (hansu[val])
			visit[val] = visit[val-1]+1;
		else
			visit[val] = visit[val-1];
	}
	return (visit[val]);
}



int		main(void)
{
	cin>>n;
	init();
	cout<<brute_force(n)<<'\n';
}