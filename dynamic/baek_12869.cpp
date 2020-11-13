#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define	MAX	62

int		visted[MAX][MAX][MAX];	
int		scv[3];
int		n;

void	init(void)
{
	memset(scv, 0, sizeof(scv));
	memset(visted, 0, sizeof(visted));
}

int		greedy(int a, int b, int c)
{
	int		ret = MAX;

	if (a < 0)
		a = 0;
	if (b < 0)
		b = 0;
	if (c < 0)
		c = 0;
	if (!a && !b && !c)
		return (0);
	if (visted[a][b][c])
		return (visted[a][b][c]);
	ret = min(ret, greedy(a-9, b-3, c-1)+1);
	ret = min(ret, greedy(a-9, b-1, c-3)+1);
	ret = min(ret, greedy(a-3, b-9, c-1)+1);
	ret = min(ret, greedy(a-3, b-1, c-9)+1);
	ret = min(ret, greedy(a-1, b-9, c-3)+1);
	ret = min(ret, greedy(a-1, b-3, c-9)+1);
	visted[a][b][c] = ret;
	return (ret);
}



int		main(void)
{
	cin>>n;
	memset(scv, 0, sizeof(scv));
	for(int i=0; i<n; i++)
		cin>>scv[i];
	cout<<greedy(scv[0], scv[1], scv[2])<<'\n';	
}