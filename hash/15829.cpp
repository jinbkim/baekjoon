#include <iostream>
#include <string>
#include <cmath>
#define	M	1234567891
#define	R	31
using namespace std;

string	str;
int			l;
long long	r=1, ans=0;

int			main(void)
{
	cin>>l>>str;
	for(int i=0; i<l; i++)
	{
		ans = (ans + (r*(str[i]-'a'+1))) % M;
		r = (r*R) % M;
	}
	cout<<ans;
}