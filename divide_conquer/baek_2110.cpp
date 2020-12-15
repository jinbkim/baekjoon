#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long	router[200002];
int			n, c;

int		cnt_router(long long val)  // 설치가능한 공유기 개수 세기
{
	int		spot=router[0];  // 첫번째에는 무조건 공유기를 설치
	int		cnt=1;

	for(int i=1; i<n; i++)
		// 거리가 val이상 떨어지면 공유기를 설치하고 숫자를셈
		if (val <= router[i]-spot && cnt++)
			spot = router[i];  // 공유기 설치
	return (cnt);
}

long long	binary_search(long long left, long long right)
{
	long long	mid, ret;

	while(left <= right)
	{
		mid = (left+right)/2;
		if (cnt_router(mid) < c)
			right = mid-1;
		else
		{
			ret = mid;
			left = mid+1;
		}
	}
	return (ret);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>c;
	for(int i=0; i<n; i++)
		cin>>router[i];
	sort(router, router+n);  // 오름차순으로 정렬
	cout<<binary_search(0, 1000000000)<<'\n';
}