#include <iostream>

using namespace std;

long long	val[5002];

int		main(void)
{
	string	input;

	cin>>input;
	val[0] = 1;
	val[1] = 1;
	if (input[0] == '0')
	{
		cout<<0<<'\n';
		return (0);
	}
	for(int i=1; i<input.size(); i++)
	{
		if ((input[i-1] == '0' && input[i] == '0') || ('3' <= input[i-1] && input[i] == '0'))
		{
			val[input.size()] = 0;
			break ;
		}
		if ((input[i] != '0' && input[i+1] != '0') && ((input[i-1] == '1') || (input[i-1] == '2' && ('0' < input[i] && input[i] <= '6'))))
			val[i+1] = (val[i] + val[i-1]) % 1000000;
		else
			val[i+1] = val[i];
	}
	cout<<val[input.size()]<<'\n';
}