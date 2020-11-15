#include <iostream>
#include <cstring>
using namespace std;

long long	visited[52][52][52][52];
long long	s, a, b, c;

long long	solve(int s, int a, int b, int c)
{
	long long	ret=0;

	if (!s)
	{
		if (!a && !b && !c)
			return (1);
		else
			return (0);
	}
	if (a<0 || b<0 || c<0 || a+b+c<s || s<a || s<b || s<c)
		return (0);
	if (visited[s][a][b][c])
		return (visited[s][a][b][c]);
	ret += solve(s-1, a-1, b, c);
	ret += solve(s-1, a, b-1, c);
	ret += solve(s-1, a, b, c-1);
	ret += solve(s-1, a-1, b-1, c);
	ret += solve(s-1, a-1, b, c-1);
	ret += solve(s-1, a, b-1, c-1);
	ret += solve(s-1, a-1, b-1, c-1);
	ret %= 1000000007;
	visited[s][a][b][c] = ret;
	return (ret);
}



int		main(void)
{
	memset(visited, 0, sizeof(visited));
	cin>>s>>a>>b>>c;
	cout<<solve(s, a, b, c)<<'\n';
}