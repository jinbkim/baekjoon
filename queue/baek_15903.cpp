#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int		main(void)
{
	priority_queue< long long, vector<long long>, greater<long long> >	pq;
	int			n, m;
	long long	data1, data2, ret;
	
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>data1;
		pq.push(data1);
	}
	for(int i=0; i<m; i++)
	{
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();
		data1 = data1+data2;
		pq.push(data1);
		pq.push(data1);
	}
	ret = 0;
	for(int i=0; i<n; i++)
	{
		ret += pq.top();
		pq.pop();
	}
	cout<<ret<<'\n';
}