#include <iostream>
using namespace std;

int		arr[12];
int		n, k;

int		greedy(void)
{
	int		cnt=0, sum=0;

	for(int i=n-1; 0<=i; i--)
	{
		sum += arr[i];
		if (k < sum)
			sum -= arr[i];
		else
		{
			cnt++;
			i++;
		}
		if (sum == k)
			break ;
	}
	return (cnt);
}



int		main(void)
{
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<greedy()<<'\n';
}