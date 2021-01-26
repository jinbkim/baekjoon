#include <iostream>
#include <algorithm>
using namespace std;

int		w[1002];
int		n, ans=1, sum=1;

int		main(void)
{
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>w[i];
	sort(w, w+n);
	if (w[0] == 1)  // 제일 작은값이 1이 아니면 답은 1임
	{
		for(int i=1; w[i]<=sum+1; i++)  // w[i]<=sum+1를 만족할때까지 반복
			sum += w[i];  // 답 갱신
		ans = sum+1;
	}
	cout<<ans<<'\n';
}