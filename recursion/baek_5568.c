#include <stdio.h>
#include <string.h>

int		arr[5000];
int		visited[11];
int		cards[11];
int		n, k, result, ret;

int		is_include (int *cards)
{
	int	i;

	i = -1;
	while (++i < result)
		if (arr[i] == ret)
			return (1);
	return (0);
}

int		num_len(int n)
{
	int	i;

	i = 0;
	while (n > 0 && ++i)
		n /= 10;
	return (i);
}

void	num_join(int n)
{
	int	len, i;

	len = num_len(n);
	i = -1;
	while (++i < len)
		ret *= 10;
	ret += n;
}

void	num_split(int n)
{
	int	len, i;

	ret -= n;
	len = num_len(n);
	i = -1;
	while (++i < len)
		ret /= 10;
}

void	put_cards(int idx)
{
	int	i;

	if (idx == k)
	{
		if (!is_include(cards))
			arr[result++] = ret;
		return ;
	}
	i = -1;
	while (++i < n)
	{
		if (visited[i])
			continue ;
		visited[i] = 1;
		num_join(cards[i]);
		put_cards(idx + 1);
		num_split(cards[i]);
		visited[i] = 0;
	}
}

void	init_zero()
{
	memset(cards, 0, sizeof(cards));
	memset(visited, 0, sizeof(visited));
	result = 0;
	ret = 0;
}

int		main(void)
{
	int	i;

	scanf("%d", &n);
	scanf("%d", &k);
	init_zero();
	i = -1;
	while (++i < n)
		scanf("%d", &cards[i]);
	put_cards(0);
	printf("%d\n", result);
}