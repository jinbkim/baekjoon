#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> dp[102];
int		diff[102];
int		n, s, m;

int		guitar(void)
{
    int     data, ret=0, cnt;
   
    dp[0].push_back(s);
    for(int i=1; i<=n; i++)
    {
		cnt = 0;
        while (!dp[i-1].empty())
        {
            data = dp[i-1].back();
            dp[i-1].pop_back();
            if (data+diff[i] <= m)
                dp[i].push_back(data+diff[i]);
            if (0 <= data-diff[i])
				dp[i].push_back(data-diff[i]);
			cnt++;
			// cout<<"i : "<<i<<", data : "<<data<<'\n';
        }
		if (!cnt)
			return (-1);
    }
	while(!dp[n].empty())
	{
		data = dp[n].back();
		ret = max(ret, data);
		dp[n].pop_back();
		// cout<<"data : "<<data<<'\n';
	}
    return (ret);
}



int		main(void)
{
	cin>>n>>s>>m;
	for(int i=1; i<=n; i++)
		cin>>diff[i];
	cout<<guitar()<<'\n';
}