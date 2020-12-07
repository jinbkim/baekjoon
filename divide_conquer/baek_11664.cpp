#include <iostream>
#include <cmath>
#include <cstdio>

double	x, y, z, xx, yy, zz, xxx, yyy, zzz;

double	dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1)));
}

double	bs(double left, double right)
{
	double	dx, dy, dz, m1, m1x, m1y, m1z, m2, m2x, m2y, m2z, d1, d2;
	
	dx = xx-x;
	dy = yy-y;
	dz = zz-z;
	while (0.00000000001 <= right-left)
	{
		m1 = left + (right-left)/3;
		m2 = right - (right-left)/3;
		m1x = x + m1*dx;
		m1y = y + m1*dy;
		m1z = z + m1*dz;
		m2x = x + m2*dx;
		m2y = y + m2*dy;
		m2z = z + m2*dz;
		d1 = dist(m1x,m1y,m1z,xxx,yyy,zzz);
		d2 = dist(m2x,m2y,m2z,xxx,yyy,zzz);
		if (d1 < d2)
			right=m2;
		else
			left=m1;
	}
	return (d1);
}



int		main(void)
{
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x, &y, &z, &xx, &yy, &zz, &xxx, &yyy, &zzz);
	printf("%.10lf\n", bs(0, 1));
}