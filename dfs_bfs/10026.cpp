#include <iostream>
#include <cstring>
using namespace std;

bool	visit1[102][102];
bool	visit2[102][102];
char	pic1[102][102];
char	pic2[102][102];
int		dy[4] = {-1,0,0,1};
int		dx[4] = {0,-1,1,0};
int		n, ret1=0, ret2=0;

void	dfs(int y, int x, char c, int type)
{
	int	ny, nx;

	if (type == 1)
		visit1[y][x] = 1;  // 방문
	else if (type == 2)
		visit2[y][x] = 1;  // 방문
	for(int i=0; i<4; i++)
	{
		ny = y+dy[i];
		nx = x+dx[i];
		if (0<=ny && ny<n && 0<=nx && nx<n)
		{
			if (!visit1[ny][nx] && type == 1 && pic1[ny][nx] == c)
				dfs(ny, nx, c, 1);
			else if (!visit2[ny][nx] && type == 2 && pic2[ny][nx] == c)
				dfs(ny, nx, c, 2);
		}
	}
}

int		main(void)
{
	memset(visit1, 0, sizeof(visit1));
	memset(visit2, 0, sizeof(visit2));
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			cin>>pic1[i][j];
			if (pic1[i][j] == 'G')  // 초록색이면
				pic2[i][j] = 'R';  // 빨간색으로 바꿈
			else
				pic2[i][j] = pic1[i][j];
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if (!visit1[i][j] && ++ret1)  // 방문하지 않았을때 카운트
				dfs(i, j, pic1[i][j], 1);
			if (!visit2[i][j] && ++ret2)  // 방문하지 않았을때 카운트
				dfs(i, j, pic2[i][j], 2);
		}
	cout<<ret1<<' '<<ret2<<'\n';
}