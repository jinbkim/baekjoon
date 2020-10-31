#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX	60000000

vector<long long>	vec;
int		n, m, cnt, upper_ans;

long long	count_num(long long val)
{
	long long	ret;

	ret = m;
	for(int i=0; i<m; i++)
		ret += val/vec[i];
	// for(int i=1; i<=val; i++)
	// 	for(int j=0; j<m; j++)
	// 		if (!(i%vec[j]))
	// 			ret++;
	return (ret);
}

int		bs(long long left, long long right)
{
	long long	mid, ans, cnt, diff, idx;

	while (left <= right)
	{
		// cout<<"left : "<<left<<", right : "<<right<<'\n';
		mid = (left+right)/2;
		if (n <= count_num(mid))
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	upper_ans = count_num(ans);
	diff = count_num(ans) - n;
	// cout<<"ans : "<<ans<<'\n';
	// cout<<"upper_ans : "<<upper_ans<<'\n';
	// cout<<"diff : "<<diff<<'\n';
	cnt = 0;
	idx = m;
	while (cnt <= diff && idx--)
	{
		if (!(ans % vec[idx]))
			cnt++;
	}
	return(vec[idx]);
}



int		main(void)
{
	long long	data;

	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);

	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>data;
		vec.push_back(data);
	}
	sort(vec.begin(), vec.end());
	cout<<bs(0, MAX)<<'\n';
}