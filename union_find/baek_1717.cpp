#include <iostream>
using namespace std;

int		node[10000002];  // 부모노드
int		n, m, a, b, c;

int		getParent(int n)
{
	if (node[n] == n)
		return (n);
	node[n] = getParent(node[n]);
	return(node[n]);
}

void	unionParent(int n1, int n2)
{
	n1 = getParent(n1);
	n2 = getParent(n2);
	if(n1 < n2)
		node[n2] = n1;
	else
		node[n1] = n2;
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>m;
	for(int i=1; i<=n; i++)
		node[i] = i;
	for(int i=0; i<m; i++)
	{
		cin>>a>>b>>c;
		if (!a)
			unionParent(b, c);  // 집합 합치기
		else if (getParent(b) == getParent(c))  // 같은 집합에 속해 있으면
			cout<<"YES\n";
		else  // 같은 집합에 속해 있지 않으면
			cout<<"NO\n";
	}
}