#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

string	a, temp;
bool	visited[12];
int		b, ret=-1, num_size;

void	init(void)
{
	num_size = a.size();
	memset(visited, 0, sizeof(visited));
}

void	bf(int idx, int sum)
{
	if (num_size < idx || b < sum)
		return ;
	if (num_size == idx)
	{
		ret = max(ret, sum);
		return ;
	}
	for(int i=0; i<num_size; i++)
	{
		if (idx == 0 && a[i] == '0')
			continue ;
		if (!visited[i])
		{
			temp.clear();
			temp += a[i];
			visited[i] = true;
			bf(idx+1, sum+stoi(temp)*pow(10, num_size-idx-1));
			visited[i] = false;
		}
	}
}



int		main(void)
{
	cin>>a>>b;
	init();
	bf(0, 0);
	cout<<ret<<'\n';
}