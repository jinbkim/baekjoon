#include <stdio.h>
#include <stdlib.h>

char	**star_init(int num)
{
	char	**arr;
	int		i;
	int		j;
	
	arr = (char **)malloc(sizeof(char *) * (num + 1));
	arr[num] = NULL;
	
	i = -1;
	while (++i < num)
	{
		arr[i] = (char *)malloc(num + 1);
		j = -1;
		while (++j < num)
			arr[i][j] = ' ';
		arr[i][j] = '\0';
	}
	return (arr);
}

void	change_star(char **star, int x, int y, int num)
{
	int i;
	int j;
	int num2;
	int count;
 
	if (num == 1)
	{
		star[x][y] = '*';
		return ;
	}
	num2 = num / 3;
	i = -1;
	count = 0;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3 && ++count)
			if (count != 5)
				change_star(star, i * num2 + x, j * num2 + y, num2);
	}
}

void	show_star(char **star, int num)
{
	int	i;
	int j;
	
	i = -1;
	while (++i < num)
	{
		j = -1;
		while (++j < num)
			printf("%c", star[i][j]);
		printf("\n");
	}
}

void	free_all(char **star, int num)
{
	int	i;
	
	i = -1;
	while (++i < num)
		free(star[i]);
	free(star);
}



int		main(void)
{
	char	**star;
	int		num;

	scanf("%d", &num);
	getchar();  // remove the enter in the buffer
	
	star = star_init(num);  // allocate memory and initialize shape
	change_star(star, 0, 0, num);  // put the star in the right place
	show_star(star, num);
	
	free_all(star, num);
}
