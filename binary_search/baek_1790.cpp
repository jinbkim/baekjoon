#include <iostream>
#include <cmath>

using namespace std;

int		boundary[11];

int		find_range(int n)
{
	int	range, sum;

	for(int i=1; i<=8; i++)
		if (n <= pow(10, i))
		{
			range = i;
			break ;
		}
	for(int i=0; i<=8; i++)
	{
		boundary[i] = 9;
		for(int j=0; j<i; j++)
			boundary[i] *= 10;
		boundary[i] *= i+1;
	}
	for(int i=1; i<=8; i++)
		boundary[i] += boundary[i-1];
	sum = boundary[range-2] + (n-pow(10,range-1)+1)*(range);
	if (sum < n)
		return (-1);
	else
		return()
}

int		bs(int n, int k)
{
	int		range;

	range = find_range(n);
	if (range == -1)
		return (-1);
	return (0);
	// if (!is_possible(n, k))
		// return (-1);
}



int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int		n, k;
	cin>>n>>k;

	cout<<bs(n, k)<<'\n';
}