#include <iostream>
#include <cmath>
using namespace std;

int     n;

void	divide_conquer(int size)
{
	if (size == 1)
	{
		cout<<'-';
		return ;
	}
	divide_conquer(size/3);
	for(int i=0; i<size/3; i++)
		cout<<' ';
	divide_conquer(size/3);
}

int     main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	while (1)
	{
		cin>>n;
		if (cin.eof())  // ctrl+d
			break ;
		divide_conquer(pow(3, n));
		cout<<'\n';
	}
}