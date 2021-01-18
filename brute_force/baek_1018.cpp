#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string	board[52];
int		w_ans[52][52];  // (0,0)가 w일때의 해를 가지는 배열
int		b_ans[52][52];  // (0,0)가b일떄의 해를 가지는 배열
int		n, m, ans=987654321;

// 잘못칠한 판을 발견하면 정답 배열의 값을 증가
void	increase_ans(int ans[][52], int a, int b)
{
	for(int i=a; 0<=i && a-8<i; i--)
		for(int j=b; 0<=j && b-8<j; j--)
			ans[i][j]++;
}

int		main(void)
{
	memset(w_ans, 0, sizeof(w_ans));
	memset(b_ans, 0, sizeof(b_ans));
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>board[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			// (0,0)가 w인경우 b자리에 w가 칠해졌을 경우
			if ((i+j)%2 && board[i][j] == 'W')
				increase_ans(w_ans, i, j);
			// (0,0)가 w인경우 w자리에 b가 칠해졌을 경우
			else if (!((i+j)%2) && board[i][j] == 'B')
				increase_ans(w_ans, i, j);
			// (0,0)가 b인경우 w자리에 b가 칠해졌을 경우
			else if ((i+j)%2 && board[i][j] == 'B')
				increase_ans(b_ans, i, j);
			// (0,0)가 b인경우 b자리에 w가 칠해졌을 경우
			else if (!((i+j)%2) && board[i][j] == 'W')
				increase_ans(b_ans, i, j);
		}
	// 최소값 구하기
	for(int i=0; i<=n-8; i++)
		for(int j=0; j<=m-8; j++)
			ans = min(ans, min(b_ans[i][j], w_ans[i][j]));
	cout<<ans<<'\n';
}