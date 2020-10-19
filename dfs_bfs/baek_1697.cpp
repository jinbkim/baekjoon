#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int		visted[100001];
int		n, k,cur_p, next_p;

void	init(void)
{
	memset(visted, 0, sizeof(visted));
}

bool	is_inside(int p)
{
	if (0 <= p && p <= 100000)
		return (true);
	else
		return (false);
}

int		get_p(int cur_p, int n)
{
	if (n == 0)
		return (cur_p-1);
	else if (n == 1)
		return (cur_p+1);
	else if (n == 2)
		return (cur_p*2);
	return (0);
}

int		bfs(void)
{
	queue<int>	q;
	
	q.push(n);
	visted[n] = 1;
	while (1)
	{
		cur_p = q.front();
		if (cur_p == k)
			break ;
		q.pop();
		for(int i=0; i<3; i++)
		{
			next_p = get_p(cur_p, i);
			if (is_inside(next_p) && !visted[next_p])
			{
				visted[next_p] = visted[cur_p]+1;
				q.push(next_p);
			}
		}
	}
	return (visted[cur_p] - 1);
}



int		main(void)
{
	init();
	cin>>n>>k;
	cout<<bfs()<<'\n';
}