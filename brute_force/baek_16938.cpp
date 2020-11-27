#include <iostream>
#include <algorithm>
using namespace std;

int		arr[17];
int		n, l, r, x, ret=0;

void	solve(int idx, int sum, int small, int big, bool flag)
{
	if (n < idx)
		return ;
	if (l<=sum && sum<=r && x<=big-small && flag)
		ret++;
	solve(idx+1, sum+arr[idx], min(small, arr[idx]), max(big, arr[idx]), 1);
	solve(idx+1, sum, small, big, 0);
}



int		main(void)
{
	cin>>n>>l>>r>>x;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	solve(0, 0, 987654321, 0, 0);
	cout<<ret<<'\n';
}