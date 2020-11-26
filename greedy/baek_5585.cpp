#include <iostream>
using namespace std;

int		main(void)
{
	int		money, ret=1;

	cin>>money;
	money = 1000-money;
	while(500 <= money && ret++)
		money -= 500;
	while(100 <= money && ret++)
		money -= 100;
	while(50 <= money && ret++)
		money -= 50;
	while(10 <= money && ret++)
		money -= 10;
	while(5 <= money && ret++)
		money -= 5;
	while(1 <= money && ret++)
		money -= 1;
	cout<<ret-1<<'\n';
}