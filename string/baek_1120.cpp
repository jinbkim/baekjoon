#include <iostream>
#include <algorithm>
using namespace std;

string	str1, str2;
int		len1, len2;
int		ans=987654321;
int		cnt;

int		main(void)
{
	cin>>str1>>str2;
	len1 = str1.size();
	len2 = str2.size();
	for(int i=0; i<=len2-len1; i++)
	{
		cnt = 0;
		for(int j=0; j<len1; j++)
			if (str1[j] != str2[i+j])
				cnt++;
		ans = min(ans, cnt);
	}
	cout<<ans<<'\n';
}