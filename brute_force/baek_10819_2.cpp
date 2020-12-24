#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>		permu;  // 인덱스 순열
int		arr[10];
int		n, ret=0;

int		cal(void)
{
	int		ret=0;

	for(int i=1; i<n; i++)
		ret += abs(arr[permu[i]]-arr[permu[i-1]]);  // 문제에서 원하는 계산
	return (ret);
}

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		permu.push_back(i);  // 순열인 인덱스 넣기
	}
	ret = max(ret, cal());  // 전에 구한 최대값보다 큰값이 나오면 해답 변경
	while(next_permutation(permu.begin(), permu.end()))  // 순열을 구하는 함수
		ret = max(ret, cal());  // 전에 구한 최대값보다 큰값이 나오면 해답 변경
	cout<<ret<<'\n';
}