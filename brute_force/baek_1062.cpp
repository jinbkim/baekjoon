#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	str[52];
bool	flag[27];  // 글자를 가르친것을 체크하는 플래그
int		n, k, ans=0;

void	init(void)
{
	memset(flag, 0, sizeof(flag));
	flag['a'-'a'] = true;
	flag['n'-'a'] = true;
	flag['t'-'a'] = true;
	flag['i'-'a'] = true;
	flag['c'-'a'] = true;
}

int		count_ans(void)
{
	int		ret=0, j, len;

	for(int i=0; i<n; i++)
	{
		len = str[i].size();
		for(j=4; j<=len-5; j++)  // 단어의 앞 anta, 단어의 끝 tica 제외
			if (!flag[str[i][j] - 'a'])
				break ;
		if (j == len-4)  // 반복문이 끝까지 돌았다는건 해당 단어를 읽을 수 있음
			ret++;
	}
	return (ret);
}

void	dfs(int start, int cnt)
{
	if (cnt == k)
	{
		ans = max(ans, count_ans());  // 최대값 변경
		return ;
	}
	for(int i=start; i<='z'-'a'; i++)  // 알파벳 소문자에 대해 반복
		if (!flag[i])
		{
			flag[i] = true;  // 백트래킹
			dfs(i+1, cnt+1);  // 이미 체크한 문자를 다시 탐색하지 않기위해 i+1
			flag[i] = false;  // 백트래킹
		}
}

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>str[i];
	init();
	if (5 <= k)
		dfs(0, 5);
	else
		ans = 0;
	cout<<ans<<'\n';
}