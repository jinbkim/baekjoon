#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue< int, vector<int>, less<int> >	    max_pq;
	priority_queue< int, vector<int>, greater<int> >    min_pq;
	int		n, data1, data2;

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>data1;
        if (i%2)
            max_pq.push(data1);
        else
            min_pq.push(data1);
        if (i > 1 && min_pq.top() < max_pq.top())
        {
            data1 = min_pq.top();
            data2 = max_pq.top();
            min_pq.pop();
            max_pq.pop();
            min_pq.push(data2);
            max_pq.push(data1);
        }
        cout<<max_pq.top()<<'\n';
    }
}