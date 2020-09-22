#include <stdio.h>

int		num_len(int n)
{
	int	i;

	i = 0;
	while (++i && n)
		n /= 10;
	return (i - 1);
}

int		get_decomp_sum(int len, int n)
{
	int	ret;
	int	i;

	ret = n;
	i = 0;
	while (++i <= len)
	{
		ret += n % 10;
		n = n / 10;
	}
	return (ret);
}

int		decomp_sum(int len, int n)
{
	int	ret;
	int	i;

	i = n - 9 * len - 1;
	while (++i < n)
		if (get_decomp_sum(len, i) == n)
			return (i);
	return (0);

}

int		main(void)
{
	int	len;
	int	n;

	scanf("%d", &n);
	len = num_len(n);
	printf("%d\n",decomp_sum(len, n));
}