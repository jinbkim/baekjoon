#include <iostream>
#include <cstring>
using namespace std;

int		arr[100002];
int		t, n, ret, s1, s2;

void	init(void)
{
	memset(arr, 0, sizeof(arr));
	ret = n;
}

int		main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		init();
		for(int j=0; j<n; j++)
		{
			cin>>s1>>s2;
			arr[s1] = s2;
		}
		s1 = arr[1];
		for(int j=2; j<=n; j++)
		{
			if (s1 < arr[j])
				ret--;
			else
				s1 = arr[j];
		}
		cout<<ret<<'\n';
	}
}