#include <stdio.h>

#define	MAX_N	10000

void	check_self_n(char *sn)
{
	int	i;

	i = 0;
	while (++i <= MAX_N)
	{
		if (i < 10)
			sn[i * 2] = '1';
		else if (i < 100)
			sn[i / 10 + i % 10 + i] = '1';
		else if (i < 1000)
			sn[i / 100 + i / 10 % 10 + i % 10 + i] = '1';
		else
			sn[i / 1000 + i / 100 % 10 + i / 10  % 10 + i % 10 + i] = '1';
		
	}
}

void	show_self_n(char *sn)
{
	int	i;

	i = 0;
	while (++i <= MAX_N)
		if (sn[i] != '1')
			printf("%d\n", i);
}

int		main(void)
{
	char	self_n[MAX_N + 100];

	check_self_n(self_n);
	show_self_n(self_n);
}