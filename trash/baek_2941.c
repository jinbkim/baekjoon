#include <stdio.h>

int		ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i] && i < n - 1)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}

int		c_alpha(char *s)
{
	int result;
	int	i;

	result = 0;
	i = -1;
	while (s[++i])
	{
		if (!ft_strncmp(s + i, "c=", 2) || !ft_strncmp(s + i, "c-", 2) || !ft_strncmp(s + i, "d-", 2) || !ft_strncmp(s + i, "lj", 2) || !ft_strncmp(s + i, "nj", 2) || !ft_strncmp(s + i, "s=", 2) || !ft_strncmp(s + i, "z=", 2))
			i += 1;
		else if (!ft_strncmp(s + i, "dz=", 3))
			i += 2;
		result++;
	}
	return (result);
}



int		main(void)
{
	char	str[100];

	scanf("%s", str);
	getchar();
	printf("%d\n", c_alpha(str));
}