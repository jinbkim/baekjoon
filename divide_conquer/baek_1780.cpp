#include <iostream>

using namespace std;

int		arr[2188][2188];
int		n, paper_n[3];

void	count_paper(int n, int row, int col)
{
	if (n == 1)
	{
		paper_n[arr[row][col]+1]++;
		return ;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if (arr[row+i][col+j] != arr[row][col])
			{
				for(int k=0; k<3; k++)
					for(int l=0; l<3; l++)
						count_paper(n/3, row+n/3*k, col+n/3*l);
				return ;
			}
		}
	paper_n[arr[row][col]+1]++;
}



int		main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>arr[i][j];
	for(int i=0; i<3; i++)
		paper_n[i] = 0;
	count_paper(n, 1, 1);
	for(int i=0; i<3; i++)
		cout<<paper_n[i]<<'\n';
}