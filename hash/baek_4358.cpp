#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, double>	m;
map<string, double>::iterator	it;
string	str;
int		cnt=0;

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while (getline(cin, str) && ++cnt)  // eof 입력시 탈출
	{
		if (m.find(str) == m.end())  // map에 해당 문자열이 없으면
			m[str] = 1;  // 그 해당 문자열의 value값에 1 저장
		else  // map에 해당 문자열이 있으면
			m[str]++;  // value값이 1증가
	}
	cout << fixed;  // 소수점을 고정시켜 표현
	cout.precision(4);  // 소수점을 4자리 까지 표현
	for(it=m.begin(); it!=m.end(); it++)
		cout<<it->first<<" "<<it->second/cnt*100<<'\n';
}