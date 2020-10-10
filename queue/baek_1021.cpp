#include <iostream>
#include <deque>

using namespace	std;

deque<int>	dq;
int		arr[51];
int		n, m, ret, cnt, dq_data;

int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<m; i++)
		cin>>arr[i];
	for(int i=1; i<=n; i++)
		dq.push_back(i);
	ret=0;
	for(int i=0; i<m; i++)
	{
		cnt = 0;
		while(1)
		{
			if (arr[i] == dq.front())
			{
				if (dq.size()/2 < cnt)
					ret += dq.size() - cnt;
				else
					ret += cnt;
				dq.pop_front();
				break ;
			}
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}
	}
	cout<<ret<<'\n';
}