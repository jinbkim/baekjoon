#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int	flag[100001][2];
int	n;

bool	compare(int n1, int n2)
{
	return (n1 > n2);
}

void	init(void)
{
	flag[0][0] = v[0];
}

int		bigger(int n1, int n2)
{
	if (n1 <= n2)
		return (n2);
	else
		return (n1);
}

void	conti_sum(void)
{
	for(int i=1; i<n; i++)
	{
		if (flag[i - 1][0] >= 0)
			flag[i][0] = flag[i - 1][0] + v[i];
		else
			flag[i][0] = v[i];
		flag[i][1] = bigger(flag[i - 1][0], flag[i - 1][1]);
	}
}

int		main(void)
{
	int	minus;

	cin>>n;
	minus = 1;
	for(int i=0; i<n; i++)
	{
		int	temp;

		cin>>temp;
		if (temp > 0)
			minus = 0;
		v.push_back(temp);
	}
	if (minus)
	{
		sort(v.begin(), v.end(), compare);
		cout<<v[0]<<endl;
		return (0);
	}
	init();
	conti_sum();
	cout<<bigger(flag[n - 1][0], flag[n - 1][1])<<endl;
}
