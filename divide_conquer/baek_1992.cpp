#include <iostream>
using namespace std;

char	arr[66][66];
int		n;

// size : 정사각형 사이즈
// y, x : 정사각형 왼쪽위 좌표
// 범위에 해당하는 배열의 값이 모드 같은지
bool	all_same(int size, int y, int x)
{
	char	cmp=arr[y][x];

	for(int i=y; i<y+size; i++)
		for(int j=x; j<x+size; j++)
			if (cmp != arr[i][j])
				return (false);
	return (true);
}

void	divide_conquer(int size, int y, int x)
{
	cout<<'(';

	// 왼쪽 위
	if (!all_same(size/2, y, x))
		divide_conquer(size/2, y, x);
	else
		cout<<arr[y][x];

	// 오른쪽 위
	if (!all_same(size/2, y, x+(size/2)))
		divide_conquer(size/2, y, x+(size/2));
	else
		cout<<arr[y][x+(size/2)];

	// 왼쪽 아래
	if (!all_same(size/2, y+(size/2), x))
		divide_conquer(size/2, y+(size/2), x);
	else
		cout<<arr[y+(size/2)][x];

	// 오른쪽 아래
	if (!all_same(size/2, y+(size/2), x+(size/2)))
		divide_conquer(size/2, y+(size/2), x+(size/2));
	else
		cout<<arr[y+(size/2)][x+(size/2)];

	cout<<')';
		
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>arr[i][j];
	if (all_same(n, 0, 0))  // 모든 숫자가 같으면
	{
		cout<<arr[0][0];
		return (0);
	}
	divide_conquer(n, 0, 0);
}