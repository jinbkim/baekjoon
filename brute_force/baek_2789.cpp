#include <iostream>
using namespace std;

int		card[102];
int		n, m, ret=0;

int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>card[i];
	for(int i=0; i<n-2; i++)
		for(int j=i+1; j<n-1; j++)
			for(int k=j+1; k<n; k++)
				if (card[i]+card[j]+card[k] <= m)
					if (ret < card[i]+card[j]+card[k])
						ret = card[i]+card[j]+card[k];
	cout<<ret<<'\n';
}