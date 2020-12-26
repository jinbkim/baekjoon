#include <iostream>
#include <cmath>
using namespace std;

int		n, r, c;

// 2^size* 2^size : 분할된 배열 사이즈
// x, y : 분할된 배열의 맨왼쪽위 좌표
// ret : 우리가 구하려는 해
void	divide_conquer(int size, int x, int y, int ret)
{
	int		base1 = pow(2, size-1);
	int		base2 = pow(4, size-1);

	if (size == 1)  // 문제를 분할 할수 있는 최소한의 크기
	{
		ret += 2*(r-y)+(c-x);
		cout<<ret<<'\n';
		exit(0);
	}
	if (r<y+base1 && c<x+base1)  // 왼쪽 위
		divide_conquer(size-1, x, y, ret);
	else if (r<y+base1 && x+base1<=c)  // 오른쪽 위
		divide_conquer(size-1, x+pow(2, size-1), y, ret+base2);
	else if (y+base1<=r && c<x+base1)  // 왼쪽 아래
		divide_conquer(size-1, x, y+pow(2, size-1), ret+2*base2);
	else  // 오른쪽 아래
		divide_conquer(size-1, x+pow(2, size-1), y+pow(2, size-1), ret+3*base2);
}

int		main(void)
{
	cin>>n>>r>>c;
	divide_conquer(n, 0, 0, 0);
}