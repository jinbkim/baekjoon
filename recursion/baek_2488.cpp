#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char	star[][6] = {"  *  "," * * ","*****"};
char	ans[7000][7000];
int		n;

void	recursion(int n, int y, int x)
{
	if (n == 3)
	{
		for(int i=0; i<3; i++)
			for(int j=0; j<5; j++)
				ans[y+i][x+j] = star[i][j];
		return ;
	}
	recursion(n/2, y, x+n/2);
	recursion(n/2, y+n/2, x);
	recursion(n/2, y+n/2, x+n);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	memset(ans, ' ', sizeof(ans));
	cin>>n;
	recursion(n, 0, 0);
	for(int i=0; i<n; i++)
	{
		ans[i][2*n] = '\0';
		cout<<ans[i]<<'\n';
	}
}