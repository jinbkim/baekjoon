#include <iostream>
#include <string>
using namespace std;

string	str;
string	temp;
bool	flag=false;

int		parsing(void)
{
	int		ret=0, i;

	for(i=0; i<=str.size(); i++)
	{
		if (str[i]=='+' || !str[i] || str[i]=='-')
		{
			ret += stoi(temp);
			if (str[i] == '-')
				flag = true;
			temp = "";
			break ;
		}
		else
			temp += str[i];
	}
	if (!flag)
	{
		for(i=i+1; i<=str.size(); i++)
		{
			if (str[i]=='+' || str[i] =='-' || !str[i])
			{
				ret += stoi(temp);
				temp = "";
				if (str[i] == '-')
					break ;
			}
			else
				temp += str[i];
		}
	}
	for(i=i+1; i<=str.size(); i++)
	{
		if (str[i]=='+' || str[i] =='-' || !str[i])
		{
			ret -= stoi(temp);
			temp = "";
		}
		else
			temp+=str[i];
	}
	return (ret);
}



int		main(void)
{
	cin>>str;
	cout<<parsing()<<'\n';
}