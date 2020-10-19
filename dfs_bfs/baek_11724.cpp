#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int>	vec[1001];
bool	visted[1001];
int		n, m, ret;

void	init(void)
{
	ret = 0;
	memset(visted, 0, sizeof(visted));
}

bool	dfs(int vtx)
{
	if (vec[vtx].empty() || visted[vtx])
		return (false);
	else
	{
		visted[vtx] = true;
		for(int i=0; i<vec[vtx].size(); i++)
			dfs(vec[vtx][i]);
		return (true);
	}
}

int		main(void)
{
	int	vtx1, vtx2;

	init();
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>vtx1>>vtx2;
		vec[vtx1].push_back(vtx2);
		vec[vtx2].push_back(vtx1);
	}
	for(int i=1; i<=n; i++)
		if (dfs(i))
			ret++;
	for(int i=1; i<=n; i++)
		if (!visted[i])
			ret++;
	cout<<ret<<'\n';
}