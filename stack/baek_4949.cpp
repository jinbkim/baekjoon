#include <iostream>
#include <stack>
using namespace std;

bool	flag;  // 거짓이면 균형잡힌 문자열이 아님
string	str;
stack<char>	s;

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while(1)
	{
		flag = true;  // 플래그 초기화
		getline(cin, str);
		if (str == ".")
			break ;
		for(int i=0; i<str.size(); i++)
		{
			if (str[i]=='[' || str[i]=='(')
				s.push(str[i]);
			else if (str[i] == ']')
			{
				if (s.empty() || s.top()!='[')  // 조건의 순서 중요
					flag = false;
				else
					s.pop();
			}
			else if (str[i] == ')')
			{
				if (s.empty() || s.top()!='(')  // 조건의 순서 중요
					flag = false;
				else
					s.pop();
			}
			if (!flag)
				break ;
		}
		if (flag && s.empty())
			cout<<"yes\n";
		else
			cout<<"no\n";
		while (!s.empty())  // 스택이 비어있지 않으면
			s.pop();  // 스택 비우기
	}
}