#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>>	v;
int	flag[501][2];
int	n;

bool	compare(vector<int> v1, vector<int> v2)
{
	return(v1[0] < v2[0]);
}

int		bigger(int n1, int n2)
{
	if (n1 <= n2)
		return (n2);
	else
		return (n1);
}

int		find_val(int idx)
{
	int	i, max, max_i;

	max = 0;
	max_i = -1;
	i = -1;
	while (++i < idx)
	{
		if (max < flag[i][0] && v[i][1] < v[idx][1])
		{
			max = flag[i][0];
			max_i = i;
		}
	}
	if (max_i == -1)
		return  (1);
	else
		return (flag[max_i][0] + 1);
}

void	electric(void)
{
	int	i;

	i = 0;
	while (++i < n)
	{
		flag[i][0] = find_val(i);
		flag[i][1] = bigger(flag[i - 1][0], flag[i - 1][1]);
	}
}

void	init(void)
{
	memset(flag, 0, sizeof(flag));
	flag[0][0] = 1;
	sort(v.begin(), v.end(), compare);
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		vector<int> vec(2);
		cin>>vec[0]>>vec[1];
		v.push_back(vec);
	}
	init();
	electric();
	cout<<n - bigger(flag[n - 1][0], flag[n - 1][1])<<endl;
}
