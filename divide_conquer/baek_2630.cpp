#include <iostream>
#include <cstring>

using namespace std;

int		arr[129][129];
int		n, white, blue;

void	init(void)
{
	memset(arr, 0, sizeof(arr));
	white = 0;
	blue = 0;
}

void	make_paper(int n, int row, int col)
{
	int	first, flag;

	first = arr[col][row];
	flag = 1;
	if (n == 1)
	{
		if (first)
			blue++;
		else
			white++;
		return ;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (arr[col+i][row+j] != first)
			{
				flag = 0;
				break ;
			}
		}
		if (!flag)
			break ;
	}
	if (!flag)
	{
		make_paper(n/2, row, col);
		make_paper(n/2, row+n/2, col);
		make_paper(n/2, row, col+n/2);
		make_paper(n/2, row+n/2, col+n/2);
	}
	else
	{
		if (first)
			blue++;
		else
			white++;
	}

}

int		main(void)
{
	init();
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>arr[i][j];
	make_paper(n, 1, 1);
	cout<<white<<'\n'<<blue<<'\n';
}