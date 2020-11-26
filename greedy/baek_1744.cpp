#include <iostream>
#include <algorithm>
using namespace std;

int		main(void)
{
	int		arr[10002];
	int		n, minus_=0, zero=0, one=0, plus_=0, i, ret=0;

	cin>>n;
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
		if (arr[i] < 0)
			minus_++;
		else if(arr[i] == 0)
			zero++;
		else if (arr[i] == 1)
			one++;
		else if (0 < arr[i])
			plus_++;
	}
	sort(arr, arr+n);

	i = 0;
	if (minus_%2 && zero)
		for(; i<minus_-1; i+=2)
			ret += arr[i]*arr[i+1];
	else if (minus_%2 && !zero)
	{
		for(; i<minus_-1; i+=2)
			ret += arr[i]*arr[i+1];
		ret += arr[minus_-1];
	}
	else if (minus_%2 == 0)
		for(; i<minus_; i+=2)
			ret += arr[i]*arr[i+1];

	ret += one;
	while (1)
	{
		if (1 < arr[i])
			break ;
		i++;
	}

	if (plus_%2)
	{
		ret += arr[i++];
		for(;i<n; i+=2)
			ret += arr[i]*arr[i+1];
	}
	else if (plus_%2 == 0)
		for(; i<n; i+=2)
			ret += arr[i]*arr[i+1];
	cout<<ret<<'\n';
}