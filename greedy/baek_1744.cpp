#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int	v[10001];
int	n, ret, zero_n;

bool	comp(int n1, int n2)
{
	return (n1 > n2);
}

void	init(void)
{
	memset(v, 0,sizeof(v));
	ret = 0;
	zero_n = 0;
}

void	tie_num(void)
{
	int	i, j;

	i = 0;
	while (1)
	{
		if (v[i] <= 1 || v[i + 1] <= 1)
			break ;
		ret += (v[i] * v[i + 1]);
		i += 2;
	}
	while (v[i] > 0)
		ret += v[i++];
	while (v[i] == 0 && i++ < n)
		zero_n++;
	j = i;
	i = n - 1;
	while (j <= i - 1)
	{
		ret += (v[i] * v[i - 1]);
		i -= 2;
	}
	for (i=i; j<=i; i--)
	{
		if (zero_n)
		{
			zero_n--;
			continue ;
		}
		ret += v[i];
	}
	cout<<ret<<endl;
}

int		main(void)
{
	init();
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	sort(v, v + n, comp);
	tie_num();
}