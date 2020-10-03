#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

string	str[11];
int		alpha[27];
int		str_len[11];
int		n, ret;

void	init(void)
{
	memset(alpha, 0, sizeof(alpha));
	ret = 0;
}

bool	comp(int n1, int n2)
{
	return (n1 > n2);
}

int		main(void)
{
	init();
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>str[i];
		str_len[i] = str[i].size();
		for(int j=str_len[i]; 0<j; j--)
			alpha[str[i][j - 1] - 'A'] += pow(10, str_len[i] - j);
	}
	sort(alpha, alpha + 26, comp);
	for(int i=0; i<26; i++)
		ret += alpha[i] * (9 - i);
	printf("%d\n", ret);
}
