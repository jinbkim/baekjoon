#include <iostream>
#include <algorithm>

using namespace std;


int		main(void)
{
	int		arr[1002];
	int		flag[1002];
	int		n, max_val;

	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>arr[i];
		flag[i] = 1;
	}
	for (int i=n-1; 0<=i; i--)
	{
		max_val = 0;
		for (int j=n-1; i<j; j--)
			if (max_val < flag[j] && arr[j] < arr[i])
				max_val = flag[j];
		flag[i] = max_val + 1;
	}
	sort(flag, flag+n);
	cout<<flag[n-1]<<'\n';
}