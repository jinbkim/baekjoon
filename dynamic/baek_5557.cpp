#include <iostream>
using namespace std;

int		arr[102];
int		n, ret=0;;

void	solve(int sum, int idx)
{
	// cout<<"sum : "<<sum<<", idx : "<<idx<<'\n';
	if (sum < 0 || 20 < sum)
		return ;
	if (idx == n-2)
	{
		if (sum == arr[n-1])
			ret++;
		return ;
	}
	solve(sum+arr[idx+1], idx+1);
	solve(sum-arr[idx+1], idx+1);
}
int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	solve(arr[0], 0);
	cout<<ret<<'\n';
}