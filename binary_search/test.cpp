#include <iostream>
#include <cmath>

using namespace std;

int		boundary[11], range;

int		find_size(int n)
{
	int		size;

	for(int i=1; i<=8; i++)
		if (n < pow(10, i))
		{
			range = i;
			break ;
		}
	size = boundary[range-2] + (n-pow(10,range-1)+1)*(range);
	// cout<<"range : "<<range<<'\n';
	// cout<<"size : "<<size<<'\n';
	// cout<<"n : "<<n<<'\n';
	return (size);
}

int		find_num(int start, int end, int ans)
{
	int		mid, size;

	while (start<=end)
	{
		mid = (start+end)/2;
		size = find_size(mid);
		// cout<<"start : "<<start<<", end : "<<end<<'\n';
		// cout<<"size : "<<size<<'\n';
		// cout<<"range : "<<range<<'\n';
		// cout<<"ans : "<<ans<<'\n';
		if (size < ans)
			start = mid+1;
		else
			end = mid-1;
	}
	int ret1 = (int)pow(10, size-ans);
	int ret2 = ((int)mid/ret1);
	ret2 = ret2 % 10;
	// int ret2 = (mid/(int)pow(10, size-ans)) % 10;
	cout<<"start : "<<start<<", end : "<<end<<'\n';
		cout<<"size : "<<size<<'\n';
		cout<<"range : "<<range<<'\n';
		cout<<"ans : "<<ans<<'\n';
	cout<<"mid : "<<mid<<", pow(10, size-ans) : "<<pow(10, size-ans)<<'\n';
	return (ret2);
}

int		bs(int n, int k)
{
	for(int i=0; i<=8; i++)
	{
		boundary[i] = 9;
		for(int j=0; j<i; j++)
			boundary[i] *= 10;
		boundary[i] *= i+1;
	}
	for(int i=1; i<=8; i++)
		boundary[i] += boundary[i-1];
	if (find_size(n) < k)
		return (-1);
	return(find_num(1, n, k));
}


int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int		n, k;
	cin>>n>>k;

	cout<<bs(n, k)<<'\n';
}