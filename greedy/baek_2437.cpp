#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int	n, ret;
vector<int> v;

bool	comp(int n1, int n2)
{
	return (n1 < n2);
}

void	init(void)
{
	sort(v.begin(), v.end(), comp);
	ret = 1;
}

void	balance(void)
{
	int	i;

	if (v[0] != 1)
		return ;
	i = 0;
	while (++i)
	{
		if (ret + 1 < v[i])
			break ;
		ret += v[i];
		if (i == n - 1)
			break ;
	}
	ret++;
}

int		main(void)
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int	temp;

		cin>>temp;
		v.push_back(temp);
	}
	init();
	balance();
	cout<<ret<<endl;
}