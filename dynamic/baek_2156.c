#include <stdio.h>
#include <string.h>

int		dp[10001];
int		arr[10001];
int		n;


int		bigger(int n1, int n2)
{
	if (n1 <= n2)
		return (n2);
	else
		return (n1);
}

void	wine(void)
{
	int	i;

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = bigger(arr[1] + arr[2], arr[0] + arr[2]);
	i = -1;
	while (++i < n)
		dp[i] = bigger(bigger(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]), dp[i - 1]);
}

int		main(void)
{
	int	i;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
		scanf("%d", &arr[i]);
	wine();
	printf("%d\n", bigger(dp[n - 1], dp[n - 2]));
}