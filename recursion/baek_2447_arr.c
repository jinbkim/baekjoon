#include <stdio.h>
#include <stdlib.h>

void	star_init(char star[][2188], int num)
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < num)
	{
		j = -1;
		while (++j < num)
			star[i][j] = ' ';
	}
}

void	change_star(char star[][2188], int x, int y, int num)
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

void	show_star(char star[][2188], int num)
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



int		main(void)
{
	char	star[2188][2188];
	int		num;

	scanf("%d", &num);
	getchar();  // remove the enter in the buffer
	
	star_init(star, num);  // allocate memory and initialize shape
	change_star(star, 0, 0, num);  // put the star in the right place
	show_star(star, num);
}
