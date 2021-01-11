#include <iostream>
#include <cstring>
using namespace std;

int		a, b, c;
int		dp[52][52][52];

int		w(int a, int b, int c)
{
	if (a<=0 || b<=0 || c<=0)
		return (1);
	if (20<a || 20<b || 20<c)
		return (w(20, 20, 20));
	if (!dp[a][b][c] && a<b && b<c)
		dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else if (!dp[a][b][c])
		dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	return (dp[a][b][c]);
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	memset(dp, 0, sizeof(dp));
	while (1)
	{
		cin>>a>>b>>c;
		if (a==-1 && b==-1 && c==-1)
			break ;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a, b, c)<<'\n';
	}
}