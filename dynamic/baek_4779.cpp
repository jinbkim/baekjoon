#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string  cantor[13];
int     n;

int     main(void)
{
    cantor[0] = '-';
    for(int i=1; i<=12; i++)
    {
        cantor[i] = cantor[i-1]; 
        cantor[i].append(pow(3,i-1), ' ');
        cantor[i] += cantor[i-1];
    }
    while (1)
    {
		cin>>n;
		if (cin.eof())  // ctrl+d
			break ;
		cout<<cantor[n]<<'\n';
    }
}