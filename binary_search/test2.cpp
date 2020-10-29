#include <iostream>
#include <cmath>
using namespace std;

string	n_str;
int		n, k, n_size;

long long	one_to_num_size(int num)
{
	long long	ret;

	n_str = to_string(num);
	n_size = n_str.length();
	ret = 0;
	for(int i=1, oper = 9; i<n_size; i++, oper*=10)
		ret += oper*i;
	ret += (num-pow(10,n_size-1)+1)*n_size;
	return (ret);
}

char	bs(int start, int end)
{
	long long	size;
	char		ret;
	int 		mid, ans;

	while (start<=end)
	{
		mid = (start+end)/2;
		size = one_to_num_size(mid);
		if (size < k)
			start = mid+1;
		else
		{
			end = mid-1;
			ans = mid;
		}
	}
	ret = to_string(ans)[n_size-one_to_num_size(ans)+k-1];
	return (ret);
}



int		main(void)
{
	cin>>n>>k;
	if (one_to_num_size(n) < k)
	{
		cout<<"-1"<<'\n';
		return (0);
	}
	cout<<bs(1, k)<<'\n';
}