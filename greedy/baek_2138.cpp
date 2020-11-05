#include <iostream>
#include <algorithm>
using namespace std;

#define	MAX 100002

string	map1, map2;
bool	map3[MAX];
bool	map4[MAX];
bool 	map5[MAX];
int		n;

void	invert_conversion(bool map[], int idx)
{
	for(int i=0; i<3; i++)
		if (0 <= idx-1+i && idx-1+i < n)
			map[idx-1+i] = !map[idx-1+i];
}

int		greedy(void)
{
	int		ret1=1, ret2=0;

	invert_conversion(map3, 0);
	for(int i=1; i<n; i++)
	{
		if (map3[i-1] != map5[i-1])
		{
			invert_conversion(map3, i);
			ret1++;
		}
		if (map4[i-1] != map5[i-1])
		{
			invert_conversion(map4, i);
			ret2++;
		}
	}
	if (map3[n-1] == map5[n-1] && map4[n-1] == map5[n-1])
		return (min(ret1, ret2));
	if (map3[n-1] == map5[n-1])
		return (ret1);
	if (map4[n-1] == map5[n-1])
		return (ret2);
	return (-1);
}



int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n;
	cin>>map1;
	cin>>map2;
	for(int i=0; i<n; i++)
	{
		map3[i] = map1[i] - '0';
		map4[i] = map1[i] - '0';
		map5[i] = map2[i] - '0';
	}
	cout<<greedy()<<'\n';
}