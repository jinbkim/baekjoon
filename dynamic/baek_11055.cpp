#include <iostream>
#include <algorithm>

using namespace std;

int		main(void)
{
	int		arr[1002];
	int		flag[1002];
	int		n, max_val;

	cin>>n;
	cin>>arr[0];
	flag[0] = arr[0];
	for(int i=1; i<n; i++)
	{
		cin>>arr[i];
		max_val = 0;
		for(int j=0; j<i; j++)
			if (max_val < flag[j] && arr[j] < arr[i])
				max_val = flag[j];
		flag[i] = max_val + arr[i];
	}
	sort(flag, flag+n);
	cout<<flag[n-1]<<'\n';
}