#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int>	hashMap1;
map<int, string>	hashMap2;
string	str;
int	n, m;

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>str;
		hashMap1[str] = i;
		hashMap2[i] = str;
	}
	for(int i=0; i<m; i++)
	{
		cin>>str;
		if (hashMap1.find(str) == hashMap1.end())
			cout<<hashMap2[stoi(str)]<<'\n';
		else
			cout<<hashMap1[str]<<'\n';
	}
}