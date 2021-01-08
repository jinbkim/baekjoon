#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool	flag;  // 문자열이 일관성이 있는지 없는지 확인하는 플래그
int		t, n;

// 문자열을 비교하는 함수
bool	ft_strncmp(string s1, string s2, int n1, int n2)
{
	for(int i=0; i<n1 && i<n2; i++)
		if(s1[i] != s2[i])
			return (true);
	return (false);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>t;
	for(int i=0; i<t; i++)
	{
		string	str[10002];  // 반복문이 돌때마다 초기화 시키기위해 지역변수로 선언함
	
		cin>>n;
		flag = true;  // 플래그 초기화
		for(int j=0; j<n; j++)
			cin>>str[j];
		sort(str, str+n);
		for(int j=0; j<n-1; j++)
		{
			// 다음 문자열이랑만 한번만 비교하면됨
			if (!ft_strncmp(str[j], str[j+1], str[j].size(), str[j+1].size()))
			{
				flag = false;
				break ;
			}
		}
		if (flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}