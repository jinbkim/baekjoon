#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector< pair<int, int> >    		vec;
vector<int>				vec2;
vector<int>::iterator	it;


int		n, pole1, pole2;

int     main(void)
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>pole1>>pole2;
        vec.push_back(make_pair(pole2, pole1));
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<n; i++)
    {
		it = lower_bound(vec2.begin(), vec2.end(), vec[i].first);
		if (it == vec2.end())
			vec2.push_back(vec[i].first);

		cout<<vec[i].second<<'\n';
		
			// it = lower_bound(vec.begin(), vec.end(), vec[i].first);
			// if (it == vec.end())
			// 	ans.push_back(vec[i].first);
			// else
			// 	an
    }
}