#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	vec;
int		n;

int		greedy(void)
{
	bool	flag=false;
	int		i, temp=0, ret=0;
	
	for(i=0; vec[i]<0 && i<n; i++)
	{
		if (!flag)
		{
			temp = vec[i];
			flag = true;
		}
		else
		{
			ret += vec[i] * temp;
			flag = false;
		}		
	}
	
	for(; vec[i]==0 && i<n; i++)
		temp=0;
	if (flag)
		ret += temp;

	for(; vec[i]== 1 && i<n; i++)
		ret++;

	if (i<n && (n-1-i)%2 == 0)
		ret += vec[i++];
	flag = false;
	for(; i<n; i++)
	{
		if (!flag)
		{
			temp = vec[i];
			flag = true;
		}
		else
		{
			ret += vec[i] * temp;
			flag = false;
		}	
	}
	return (ret);
}



int		main(void)
{
	int		data;

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	cout<<greedy()<<'\n';
}