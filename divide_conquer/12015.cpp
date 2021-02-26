#include <iostream>
#include <vector>
using namespace std;

vector<int>				ans;
vector<int>::iterator	it;
int	n, numData;

int		main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>numData;
        // numData보다 크거나 같은 값의 iterator값 반환
		it = lower_bound(ans.begin(), ans.end(), numData);
		if (it == ans.end())  // ans안에 numData보다 큰값이 없으면
			ans.push_back(numData);  // 수열에 numData 넣기
		else
			// numData보다 크거나 같은 값의 가지는 값을 numData로 갱신
			*it = numData;
	}
	cout<<ans.size();
}