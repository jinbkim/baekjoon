#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string	gear[4];
int		gear_left[4];  // 톱니바퀴가 맞닿는 부분의 왼쪽
int		gear_right[4];  // 톱니바퀴가 맞닿는 부분의 오른쪽

void	init(void)
{
	for(int i=0; i<4; i++)
	{
		gear_left[i] = 6;  // 톱니바퀴가 맞닿는 부분의 왼쪽을 나타내는 문자열의 초기 인덱스는 6
		gear_right[i] = 2;  // 톱니바퀴가 맞닿는 부분의 오른쪽을 나타내는 문자열의 초기 인덱스는 2
	}
}

void	counter_clock_wise(int idx)  // 반시계 방향으로 시계 돌기
{
	gear_left[idx]++;  // 반시계 방향으로 돌면 톱니바퀴가 맞닿는 부분의 왼쪽의 인덱스가 늘어남
	if (7 < gear_left[idx])  // 인덱스의 범위는 0~7
		gear_left[idx] = 0;
	gear_right[idx]++;  // 반시계 방향으로 돌면 톱니바퀴가 맞닿는 부분의 오른쪽의 인덱스가 늘어남
	if (7 < gear_right[idx])  // 인덱스의 범위는 0~7
		gear_right[idx] = 0;
}

void	clock_wise(int idx)
{
	gear_left[idx]--;  // 시계 방향으로 돌면 톱니바퀴가 맞닿는 부분의 왼쪽의 인덱스가 줄어듬
	if (gear_left[idx] < 0)  // 인덱스의 범위는 0~7
		gear_left[idx] = 7;
	gear_right[idx]--;  // 시계 방향으로 돌면 톱니바퀴가 맞닿는 부분의 오른쪽의 인덱스가 줄어듬
	if (gear_right[idx] < 0)  // 인덱스의 범위는 0~7
		gear_right[idx] = 7;
}

void	rotation(int idx, int dir)
{
	int		i, j, dir2=dir*-1, dir3=dir*-1;

	for(i=idx-1; 0<=i; i--)  // 회전시키는 톱니바퀴의 왼쪽을 어디까지 회전시킬지 탐색
		if (gear[i][gear_right[i]] == gear[i+1][gear_left[i+1]])
			break ;
	for(j=idx-1; i<j && 0<=j; j--)  // 위에서 탐색한 만큼 회전시키기
	{
		if (dir2 == -1)
			counter_clock_wise(j);
		else
			clock_wise(j);
		dir2 *= -1;
	}
	for(i=idx+1; i<4; i++)  // 회전시키는 톱니바퀴의 오른쪽을 어디까지 회전시킬지 탐색
		if (gear[i-1][gear_right[i-1]] == gear[i][gear_left[i]])
			break ;
	for(j=idx+1; j<i && j<4; j++)  // 위에서 탐색한 만큼 회전시키기
	{
		if (dir3 == -1)
			counter_clock_wise(j);
		else
			clock_wise(j);
		dir3 *= -1;
	}
	// 회전시키기로한 톱니바퀴 회전
	if (dir == -1)
		counter_clock_wise(idx);
	else if (dir == 1)
		clock_wise(idx);
}

int		calculate(void)
{
	int		ret, ans=0;

	for(int i=0; i<4; i++)
	{
		ret = gear_right[i]-2;  // 12시방향의 인덱스는 톱니바퀴가 맞닿는 부분의 오른쪽 인덱스에 -2 한값
		if (ret < 0)  // 인덱스의 범위는 0~7
			ret += 8;
		ans += pow(2, i)*(gear[i][ret]-'0');  // 문제에서 제시한 답을 구하는방법
	}
	return (ans);
}



int		main(void)
{
	int		k, idx, dir;

	init();  // 톱니바퀴가 맞닿는 부분의 왼쪽과 오른쪽 인덱스 초기화
	for(int i=0; i<4; i++)
		cin>>gear[i];
	cin>>k;
	for(int i=0; i<k; i++)
	{
		cin>>idx>>dir;
		rotation(idx-1, dir);  // 톱니바퀴 회전
	}
	cout<<calculate()<<'\n';  // 회전시킨 톱니바퀴로 답 구하기
}