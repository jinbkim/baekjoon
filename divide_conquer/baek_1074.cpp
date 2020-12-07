#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int		n, r, c, val=-1;

// x1, y1 : 사각형의 왼쪽 위 모서리
// x2, y2 : 사각형의 오른쪽 아래 모서리
void	divide_conquer(int size, int x1, int y1, int x2, int y2)
{
	// 더이상 분할하지 않는 작은 문제의 해를 구함 (정복)
	if (size == 1)
	{
		if (x1<=c && c<=x2 && y1<=r && r<=y2)
		{
			if (r==y1 && c==x1)
				val++;
			else if (r==y1 && c==x2)
				val+=2;
			else if (r==y2 && c==x1)
				val+=3;
			else if (r==y2 && c==x2)
				val+=4;
			cout<<val<<'\n';
			exit(0);
		}
		else
			val += 4;
		return ;
	}
	// 문제를 여러개의 작은 문제들로 분할 (분할)
	divide_conquer(size-1, x1, y1, (x1+x2+1)/2-1, (y1+y2+1)/2-1);
	divide_conquer(size-1, (x1+x2+1)/2, y1, x2, (y1+y2+1)/2-1);
	divide_conquer(size-1, x1, (y1+y2+1)/2, (x1+x2+1)/2-1, y2);
	divide_conquer(size-1, (x1+x2+1)/2, (y1+y2+1)/2, x2, y2);
}



int		main(void)
{
	cin>>n>>r>>c;
	divide_conquer(n, 0, 0, pow(2,n)-1, pow(2,n)-1);
}