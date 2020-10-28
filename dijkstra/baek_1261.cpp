// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;

// #define	MAX 102
// #define	INF	987654321

// vector < pair<int, int> >	vec[MAX][MAX];
// string	map[MAX];
// long long	min_d[MAX][MAX];
// int		n, m;

// void	init(void)
// {
// 	for(int i=1; i<=n; i++)
// 		for(int j=1; j<=m; j++)
// 			min_d[i][j] = INF;
// 	min_d[1][1] = 0;
// }

// int		dijkstra(int n, int m)
// {
// 	priority_queue< pair<int, int> >	pq;
// 	int	x1, y1, x2, y2;

// 	pq.push(make_pair(1, 1));
// 	while(!pq.empty())
// 	{
// 		cout<<"pq size : "<<pq.size()<<'\n';
// 		x1 = pq.top().second;
// 		y1 = pq.top().first;
// 		pq.pop();
// 		for(int i=0; i<vec[y1][x1].size(); i++)
// 		{
// 			x2 = vec[y1][x1][i].second;
// 			y2 = vec[y1][x1][i].first;
// 			if (min_d[y1][x1]+1 < min_d[y2][x2])
// 			{
// 				min_d[y2][x2] = min_d[y1][x1]+1;
// 				cout<<"x1 : "<<x1<<", y1 : "<<y1<<'\n';
// 				cout<<"min_d[y1][x1] : "<<min_d[y1][x1]<<'\n';
// 				cout<<"x2 : "<<x2<<", y2 : "<<y2<<'\n';
// 				cout<<"min_d[y2][x2] : "<<min_d[y2][x2]<<'\n';
// 				pq.push(make_pair(y2, x2));
// 			}
// 		}
// 	}
// 	return (min(min_d[n][m-1], min_d[n-1][m]));
// }

// int		main(void)
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	cin>>n>>m;
// 	for(int i=1; i<=n; i++)
// 		for(int j=1; j<=m; j++)
// 			cin>>map[i][j];

// 	for(int i=1; i<=n; i++)
// 		for(int j=1; j<=m; j++)
// 		{
// 			if (i != 1 && map[i-1][j] == '1')
// 				vec[i][j].push_back(make_pair(i-1, j));
// 			if (i != n && map[i+1][j] == '1')
// 				vec[i][j].push_back(make_pair(i+1, j));
// 			if (j != 1 && map[i][j-1] == '1')
// 				vec[i][j].push_back(make_pair(i, j-1));
// 			if (j != m && map[i][j+1] == '1')
// 				vec[i][j].push_back(make_pair(i, j+1));
// 		}
// 	init();
// 	cout<<dijkstra(n, m)<<'\n';
// }