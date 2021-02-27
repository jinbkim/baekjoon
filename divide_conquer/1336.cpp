#include <iostream>
#include <vector>
using namespace std;

vector<int>				vec;
vector<int>::iterator	it;

int n, line;

int     main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++)
	{
		cin>>line;
		it = lower_bound(vec.begin(), vec.end(), line);
		if (it == vec.end())
			vec.push_back(line);
		else
			*it = line;
	}
	cout<<n-vec.size();
}