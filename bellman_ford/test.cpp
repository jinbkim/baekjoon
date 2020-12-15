#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, pair<int, int> > >    edge;
int     dis[502];
int     tc, n, m, w, from, to, weight;

void    init(void)
{
    edge.clear();
    for(int i=1; i<=n; i++)
        dis[i] = 987654321;
}

bool    bellman_ford(int start)
{
    dis[start] = 0;
    for(int i=0; i<=n; i++)
        for(int j=0; j<edge.size(); j++)
        {
            from = edge[j].second.first;
            to = edge[j].second.second;
            weight = edge[j].first;
            if (dis[from]+weight < dis[to])
            {
                dis[to] = dis[from]+weight;
                if (i == n)
                    return (true);
            }
        }
    return (false);
}

int     main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>tc;
    for(int i=0; i<tc; i++)
    {
        init();
        cin>>n>>m>>w;
        for(int j=0; j<m; j++)
        {
            cin>>from>>to>>weight;
            edge.push_back(make_pair(weight, make_pair(from, to)));
            edge.push_back(make_pair(weight, make_pair(to, from)));
        }
        for(int j=0; j<w; j++)
        {
            cin>>from>>to>>weight;
            edge.push_back(make_pair(-weight, make_pair(from, to)));
        }
        if (bellman_ford(1))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}