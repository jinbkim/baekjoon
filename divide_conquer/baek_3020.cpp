#include <cstring>
#include <algorithm>
using namespace std;

#define	MAX	500002

long long	down[MAX] = {0, };
long long	up[MAX] = {0, };
long long	down_cnt[MAX];
long long	up_cnt[MAX];
long long	n, h, idx, ans=MAX, ans_cnt=0;

int		main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin>>n>>h;
	for(int i=1; i<=n; i++)
	{
		cin>>idx;
		if (i%2)
			down[idx]++;
		else
			up[idx]++;
	}
	down_cnt[1] = n/2+n%2;
	for(int i=2; i<=h; i++)
		down_cnt[i] = down_cnt[i-1]-down[i-1];
	up_cnt[h] = n/2;
	for(int i=h-1; 1<=i; i--)
		up_cnt[i] = up_cnt[i+1]-up[h-i];
	for(int i=1; i<=h; i++)
		ans = min(ans, down_cnt[i]+up_cnt[i]);
	for(int i=1; i<=h; i++)
		if (ans == down_cnt[i]+up_cnt[i])
			ans_cnt++;
	cout<<ans<<" "<<ans_cnt<<'\n';
}