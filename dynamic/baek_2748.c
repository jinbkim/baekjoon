#include <stdio.h>
#include <string.h>

long long	arr[100];
long long	n;

void		init(void)
{
	memset(arr, -1, sizeof(arr));
	arr[0] = 0;
	arr[1] = 1;
}

long long	fibo(long long idx)
{
	if (arr[idx] >= 0)
		return (arr[idx]);
	else
	{
		arr[idx] = fibo(idx - 1) + fibo(idx - 2);
		return (arr[idx]);
	}
}

int			main(void)
{
	scanf("%lld", &n);
	init();
	printf("%lld\n", fibo(n));
}