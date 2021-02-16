#include <iostream>
using namespace std;

int main()
{
	int price;
	int cnt;
	int left;
	int	coin[6] = {500, 100, 50, 10, 5, 1};
	int i;

	cin >> price;
	i = 0;
	left = 1000 - price;

	while (left > 0)
	{
		if (left - coin[i] < 0)
			i++;
		else
		{
			left -= coin[i];
			cnt++;
		}
	}
	cout << cnt << '\n';
}