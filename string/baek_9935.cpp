#include <iostream>
#include <cstring>
using namespace std;

int		main(void)
{
	string	str1, str2;
	char	ans[1000002];
	cin>>str1;
	cin>>str2;
	int	size1 = str1.size();
	int	size2 = str2.size();
	int	size3 = 0;  // 정답 문자열의 크기
	int	last = str2[size2-1];  // 폭발 문자열의 마지막 문자

	for(int i=0; i<size1; i++)
	{
		ans[++size3-1] = str1[i];  // 정답 문자열에 문자열 추가
		if (last == str1[i])  // 폭발 문자열의 마지막 문자와 추가된 문자가 같다면
		{
			int j;
			for(j=0; j<size2; j++)
				if (ans[size3-1-j]!= str2[size2-1-j])  // 폭발 문자열이 아니라면
					break ;
			if (j == size2)  // 반복문이 끝까지 다돌았다는건 폭발 문자열을 발견한것임
				size3 -= j;  // 폭발 문자열을 발견했으므로 정답 문자열 크기 줄이기
		}
	}
	ans[size3] = '\0';  // 마지막에 널문자 추가
	if (size3)
		cout<<ans<<'\n';
	else
		cout<<"FRULA\n";
}