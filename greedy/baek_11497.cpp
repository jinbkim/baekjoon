#include <iostream>
#include <algorithm>
using namespace std;

int		arr[10002];
int		t, n, diff;

int		main(void)
{
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		for(int j=0; j<n; j++)
			cin>>arr[j];
		sort(arr, arr+n);

		// 홀수번호 통나무들 오름차순으로 세우기
		diff = arr[2]-arr[0];
		for(int j=4; j<n; j+=2)
			diff = max(diff, arr[j]-arr[j-2]);

		// 짝수번호 통나무들 내림차순으로 세우기
		diff = max(diff, arr[n-1]-arr[n-2]);
		if(n % 2)  // 통나무 개수가 홀수 일때
			for(int j=n-2; 3<=j; j-=2)
				diff = max(diff, arr[j]-arr[j-2]);
		else  // 통나무 개수가 짝수 일때
			for(int j=n-1; 3<=j; j-=2)
				diff = max(diff, arr[j]-arr[j-2]);
		diff = max(diff, arr[1]-arr[0]);

		cout<<diff<<'\n';
	}
}