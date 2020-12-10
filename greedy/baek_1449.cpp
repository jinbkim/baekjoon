#include <iostream>
#include <algorithm>
using namespace std;

bool	flag = true;  // 인덱스를 플러스 해주어야 할떄를 알려주는 플래그
int		arr[1002];
int		n, l, ret=0, start;

int		main(void)
{
	cin>>n>>l;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	for(int i=0; i<n; ret++)
	{
		if (!flag)  // 필요에따라 인덱스를 플러스해줌
			i++;
		flag = false;  // 플래그 초기화
		start=arr[i];  // 테이프를 붙이는 시작점
		while (i<n && arr[i] <= start+l-1 && ++i)  // 테이프를 붙이므로써 물이새는 인접한 위치의 인덱스는 넘어감
			flag = true;  // 인덱스가 한번더 넘어가지 않도록 플래그를 바꿔줌
	}
	cout<<ret<<'\n';
}
