#include <iostream>
#include <cstring>
using namespace std;

int		board[17][17];
int		n, cnt=0;

int		cnt_queen(int y, int x)
{
	int		ret=0;
	if (board[y][x])
		ret++;
	for(int i=y+1; i<n; i++)
		if (board[i][x])
			ret++;
	for(int i=x+1; i<n; i++)
		if (board[y][i])
			ret++;
	for(int i=y+1, j=x+1; i<n&&j<n; i++, j++)
		if (board[i][j])
			ret++;
	for(int i=y+1, j=x-1; i<n&&0<=j; i++, j--)
		if (board[i][j])
			ret++;
	// cout<<"y : "<<y<<", x : "<<x<<", ret : "<<ret<<'\n';
	return (ret);
}

bool	is_possible(void)
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (board[i][j] && cnt_queen(i, j) != 1)
				return (false);
	return (true);
}

void	brute_force(int idx)
{
	if (idx == n)
	{
		// cout<<"==============\n";
		// for(int i=0; i<n; i++)
		// {
		// 	for(int j=0; j<n; j++)
		// 		cout<<board[i][j];
		// 	cout<<'\n';
		// }
		if (is_possible())
			cnt++;
		return ;
	}
	for(int i=0; i<n; i++)
	{
		board[idx][i] = true;
		brute_force(idx+1);
		board[idx][i] = false;
	}
}

int		main(void)
{
	cin>>n;
	memset(board, 0, sizeof(board));
	brute_force(0);
	cout<<cnt;
}