#include <iostream>
#include <cstring>

using namespace std;

long long	end_digit[1001][10];

void	init(void)
{
	memset(end_digit, 0, sizeof(end_digit));
	for(int i=0; i<10; i++)
		end_digit[1][i] = 1;
}

void	dp(int n)
{
	for(int i=2; i<=n; i++)
	{
		end_digit[i][0] += end_digit[i-1][0];
		for(int j=1; j<10; j++)
		{
			for(int k=0; k<=j; k++)
				end_digit[i][j] += end_digit[i-1][k];
			end_digit[i][j] %= 10007;
		}
	}
}



int		main(void)
{
	int			n;
	long long	ret;
	init();
	cin>>n;
	dp(n);
	ret = 0;
	for(int i=0; i<10; i++)
		ret += end_digit[n][i];
	cout<<ret%10007<<'\n';
}