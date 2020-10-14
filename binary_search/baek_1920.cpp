#include <iostream>
#include <algorithm>

using namespace std;

int		arr[100001];
int		n, m, l;

void	find_num(int l)
{
	int	start, mid, end;

	start = 0;
	end = n-1;
	while (start <= end)
	{
		mid = (start+end)/2;
		if (arr[mid] == l)
		{
			cout<<1<<'\n';
			return ;
		}
		else if (arr[mid] < l)
			start = mid+1;
		else
			end = mid-1;
	}
	cout<<0<<'\n';
}



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
		find_num(l);
	}
}