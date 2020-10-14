#include <iostream>

using namespace std;

char	arr[65][65];
int		n;

void	quad_tree(int n, int row, int col)
{
	if (n == 1)
	{
		cout<<arr[row][col];
		return ;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[row+i][col+j] != arr[row][col])
			{
				cout<<'(';
				quad_tree(n/2, row, col);
				quad_tree(n/2, row, col+n/2);
				quad_tree(n/2, row+n/2, col);
				quad_tree(n/2, row+n/2, col+n/2);
				cout<<')';
				return ;
			}
		}
	}
	cout<<arr[row][col];
}

int		main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>arr[i][j];
	quad_tree(n, 1, 1);
	cout<<'\n';
}
