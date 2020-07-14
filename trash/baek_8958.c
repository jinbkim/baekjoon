#include <stdio.h>

int		grade(char *w)
{
	int	result;
	int	conti;
	int	i;

	i = -1;
	result = 0;
	conti = 0;
	while (w[++i])
	{
		if (w[i] == 'O')
			result += ++conti;
		else
		conti = 0;
	}
	return (result);
}

int		main(void)
{
	char	words[81];
	int		n;
	int		i;

	scanf("%d", &n);
	getchar();
	i = -1;
	while (++i < n)
	{
		scanf("%s", words);
		getchar();
		printf("%d\n", grade(words));
	}
}