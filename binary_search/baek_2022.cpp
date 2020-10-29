#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double	x, y, c;

double	bs(void)
{
	double l, r, m, h1, h2, h;

	l = 0;
	r = min(x, y);
	for(int i=0; i<10000; i++)
	{
		m = (l+r) / 2;
		h1 = sqrt(x*x-m*m);
		h2 = sqrt(y*y-m*m);
		h = (h1*h2)/(h1+h2);
		if (c < h)
			l=m;
		else
			r=m;
	}
	return (m);
}



int		main(void)
{
	scanf("%lf %lf %lf", &x, &y, &c);
	printf("%.3lf\n",bs());
}