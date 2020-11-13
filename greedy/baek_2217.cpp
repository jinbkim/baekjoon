#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100002

long long	arr[MAX];
int		n;

long long	greedy(void)
{
	long long	ret=0;

	for(int i=0; i<n; i++)
		ret = max(ret, arr[n-1-i]*(i+1));
	return (ret);
}



int			main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	cout<<greedy()<<'\n';
}