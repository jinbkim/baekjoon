#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string	str;
string	arr[1002];
int		len;

int		main(void)
{
	cin>>str;
	len = str.size();
	for(int i=0; i<len; i++)
		arr[i] = &str[i];
	sort(arr, arr+len);
	for(int i=0; i<len; i++)
		cout<<arr[i]<<'\n';
}