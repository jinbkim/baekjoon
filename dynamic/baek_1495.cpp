#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int		dp[1002];
int		diff[102];
int		n, s, m;

int		guitar(void)
{
	vector<int>	vec1, vec2;
	int		ret=0, data, cnt;

	vec1.push_back(s);
	for(int i=1; i<=n; i++)
	{
		if (i%2)
		{
			while (!vec1.empty())
			{
				data = vec1.back();
				if (i == n)
					ret = max(ret, data);
				if (ret == m)
					return (ret);
				vec1.pop_back();
				if (data+diff[i] <= m)
					vec2.push_back(data+diff[i]);
				if (0 <= data-diff[i])
					vec2.push_back(data-diff[i]);
				cout<<"data : "<<data<<", i : "<<i<<'\n';
			}
		}
		else
		{
			while (!vec2.empty())
			{
				data = vec2.back();
				if (i == n)
					ret = max(ret, data);
				if (ret == m)
					return (ret);
				vec2.pop_back();
				if (data+diff[i] <= m)
					vec1.push_back(data+diff[i]);
				if (0 <= data-diff[i])
					vec1.push_back(data-diff[i]);
				cout<<"data : "<<data<<", i : "<<i<<'\n';
			}
		}
	}
	if (n%2)
	{
		
	}
	else
	{

	}
	return (ret);
}



int		main(void)
{
	cin>>n>>s>>m;
	for(int i=1; i<=n; i++)
		cin>>diff[i];
	memset(dp, 0, sizeof(dp));
	cout<<guitar()<<'\n';
}