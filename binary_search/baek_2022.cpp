#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double		x, y, c;

double	bs(double left, double right)
{
	double	mid;

	while (0.0001 <= right-left)
	{
		mid = (left+right)/2;
		if (1/c <= (1/sqrt(y*y - mid*mid)) + (1/sqrt(x*x - mid*mid)))
			right = mid;
		else
			left = mid;
	}
	return (mid);
}



int		main(void)
{
	scanf("%lf %lf %lf", &x, &y, &c);
	printf("%.3lf", bs(0, min(x, y)));
}