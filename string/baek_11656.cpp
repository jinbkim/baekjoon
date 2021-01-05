#include <iostream>
#include <algorithm>
using namespace std;

int		len;
string	str;
string	arr[1002];

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>str;
	len = str.size();
	for(int i=0; i<len; i++)
		arr[i] = &str[i];
	sort(arr, arr+len);
	for(int i=0; i<len; i++)
		cout<<arr[i]<<'\n';
}