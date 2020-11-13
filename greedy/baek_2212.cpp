#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000

int		main(void)
{
	int		arr1[MAX], arr2[MAX];
	int		n, k, ret=0;

	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>arr1[i];
	sort(arr1, arr1+n);
	for(int i=0; i<n-1; i++)
		arr2[i] = arr1[i+1]-arr1[i];
	sort(arr2, arr2+n-1);
	for(int i=0; i<n-k; i++)
		ret += arr2[i];
	cout<<ret<<'\n';
}