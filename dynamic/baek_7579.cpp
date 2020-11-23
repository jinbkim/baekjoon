#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define	MAX	1000002

int		dp1[MAX], dp2[MAX];
int 	memory[102], cost[102];
int 	n, m;

void	init(void)
{
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
}

int		solve(void)
{
	int		ret;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=MAX; j++)
        {
            if (i%2)
            {
                if (0 <= j-cost[i])
				    dp1[j] = max(dp2[j], dp2[j-cost[i]]+memory[i]);
				else
					dp1[j] = max(dp1[j], dp2[j]);
            }
            else
            {
                if (0 <= j-cost[i])
				    dp2[j] = max(dp1[j], dp1[j-cost[i]]+memory[i]);\
				else
					dp2[j] = max(dp1[j], dp2[j]);	
            }
        }
	for(int i=0; i<=MAX; i++)
		if(m <= dp1[i] || m <= dp2[i])
			return (i);
	return (0);
}



int		main(void)
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>memory[i];
	for(int i=0; i<n; i++)
		cin>>cost[i];
	init();
	cout<<solve()<<'\n';
}