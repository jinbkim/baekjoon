#include <iostream>
#include <cstring>
using namespace std;

char	str[32];
bool	visited[32][32][437];
int		n, k;

void	init(void)
{
	memset(visited, 0, sizeof(visited));
}

bool	solve(int idx, int a, int b, int sum)
{
	if (idx == n)
	{
		if (sum == k)
			return (true);
		else
			return (false);
	}
	if (visited[a][b][sum])
		return (false);
	visited[a][b][sum] =  true;
	str[idx] = 'A';
	if (solve(idx+1, a+1, b, sum))
		return (true);
	str[idx] = 'B';
	if (solve(idx+1, a, b+1, sum+a))
		return (true);
	str[idx] = 'C';
	if (solve(idx+1, a, b, sum+a+b))
		return (true);
	return (false);
}



int		main(void)
{
	init();
	cin>>n>>k;
	if (solve(0, 0, 0, 0))
		cout<<str<<'\n';
	else
		cout<<-1<<'\n';
}