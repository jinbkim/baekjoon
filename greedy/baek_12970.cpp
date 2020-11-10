#include <iostream>
using namespace std;

int		main(void)
{
	int		n, k, odd_flag=0, ret, quot, remain, remain_flag=0;

	cin>>n>>k;
	if ((n%2 && (n/2)*(n/2+1) < k) || (!(n%2) && (n/2)*(n/2) < k))
		cout<<-1<<'\n';
	else
	{
		if (n%2)
			odd_flag = 1;
		quot = k/(n/2+odd_flag);
		remain = k%(n/2+odd_flag);
		for(int i=0; i<quot; i++)
			cout<<'A';
		for(int i=0; i<n/2+odd_flag-remain; i++)
			cout<<'B';
		if (remain)
		{
			cout<<'A';
			remain_flag = 1;
		}
		for(int i=0; i<remain; i++)
			cout<<'B';
		for(int i=0; i<n/2-quot-remain_flag; i++)
			cout<<'A';
	}
}