#include <iostream>
#include <cstring>
using namespace std;

int		height[12];
int		n, order;

int		main(void)
{
	memset(height, 0, sizeof(height));  // 아직 접근하지 않은 곳은 0으로 초기화
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>order;  // 입력 : 키가 1부터 n까지 차례대로 왼쪽에 자신보다 키가 큰 사람들의 수
		for(int j=1; j<=n; j++)  // 그리디하게 앞에서부터 채워나가기
		{
			if (!order)  // 채울 장소 찾음
			{
				for(;height[j];j++)  // 이미 채워진곳이면 지나감
					;
				height[j] = i;
				break ;
			}
			if (!height[j])  // 안채워진 곳은 키가 큰 사람이므로 카운트 해줌
				order--;
		}
	}
	for(int i=1; i<=n; i++)
		cout<<height[i]<<' ';
}