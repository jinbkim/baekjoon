#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

void	vec_print(vector<int> &v, int n)
{
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<"\n\n";
}



int     main(void)
{
    vector<int> v1, v2, v3;
	vector< pair<int, bool> >	v4;
	vector<int>::iterator iter1, iter2, iter3;
	vector< pair<int, bool> >::iterator	iter4;

    for(int i=1; i<=5; i++)
	{
        v1.push_back(i);
        v2.push_back(i);
		v3.push_back(i);
		v4.push_back(make_pair(i, true));
	}
	cout<<"----- vector pop_back -----\n";
	v1.pop_back();
	cout<<"front : "<<v1.front()<<", back : "<<v1.back()<<"\n\n";

	v1.clear();
	cout<<"----- vector clear -----\n";
	cout<<"vector is empty? : ";
	if(v1.empty())
		cout<<"yes!\n\n";
	else
		cout<<"no!\n\n";
	
	cout<<"----- use iterator -----\n";
	iter1 = v2.begin();
	iter2 = v3.begin()+1;
	iter3 = v3.end()-1;
	v2.insert(iter1, 100);
	v2.insert(iter1, iter2, iter3);
	vec_print(v2, v2.size());

	cout<<"----- erase -----\n";
	iter1 = v2.begin()+1;
	v2.erase(iter1);
	iter1 = v2.end()-3;
	iter2 = v2.end()-1;
	v2.erase(iter1, iter2);
	vec_print(v2, v2.size());

	cout<<"----- lower, upper -----\n";
	sort(v2.begin(), v2.end());
	vec_print(v2, v2.size());
	iter1 = lower_bound(v2.begin(), v2.end(), 2);
	iter2 = upper_bound(v2.begin(), v2.end(), 2);
	cout<<"iter1-1 : "<<*(iter1-1)<<'\n';
	cout<<"iter1   : "<<*iter1<<'\n';
	cout<<"iter1+1 : "<<*(iter1+1)<<'\n';
	cout<<"iter2-1 : "<<*(iter2-1)<<'\n';
	cout<<"iter2   : "<<*iter2<<'\n';
	cout<<"iter2+1 : "<<*(iter2+1)<<"\n\n";

	cout<<"----- pair -----\n";
	iter4 = v4.begin();
	for(int i=0; i<5; i++)
		cout<<"<"<<(iter4+i)->first<<", "<<(iter4+i)->second<<">\n";
}