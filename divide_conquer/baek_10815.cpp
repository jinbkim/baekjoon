#include <iostream>
#include <cstring>
using namespace std;

bool	visit[20000000];
int		n, m, idx;

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, 0, sizeof(visit));
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>idx;
		visit[idx+10000000] = true;
	}
	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>idx;
		if (visit[idx+10000000])
			cout<<1<<' ';
		else
			cout<<0<<' ';
	}
}