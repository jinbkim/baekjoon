#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>	vec;
int		n;

int		main(void)
{
	cin>>n;
	for(int i=1; i<=n; i++)
		vec.push_back(i);
	for(int i=0; i<n; i++)
		cout<<vec[i]<<' ';
	cout<<'\n';
	while (next_permutation(vec.begin(), vec.end()))  // 순열 구하는 함수 사용
	{
		for(int i=0; i<n; i++)
			cout<<vec[i]<<' ';
		cout<<'\n';
	}
}