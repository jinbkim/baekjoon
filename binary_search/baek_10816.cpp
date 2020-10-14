#include <iostream>
#include <algorithm>

using namespace std;

int		arr[500000];
int		n, m, l;



int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>l;
		cout<<upper_bound(arr, arr+n, l) - lower_bound(arr, arr+n, l)<<' ';
	}
	cout<<'\n';
}