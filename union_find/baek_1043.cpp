#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int>	party[52];
bool		truth[52];
bool		party_flag[52];
int			n, m, l, man, man_n;



int		main(void)
{
	cin>>n>>m>>l;
	memset(truth, 0, sizeof(truth));
	memset(party_flag, 0, sizeof(party_flag));
	for(int i=0; i<l; i++)
	{
		cin>>man;
		truth[man] = true;
	}
	for(int i=0; i<m; i++)
	{
		cin>>man_n;
		for(int j=0; j<man_n; j++)
		{
			cin>>man;
			party[i].push_back(man);
			if (truth[man])
				party_flag[i] = true;
		}
		if (party_flag[i])
			for(int j=0; j<man_n; j++)
				truth[party[i][j]] = true;
	}
	
}