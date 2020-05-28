#include <stdio.h>

int		hanoi_count(int num)
{
	int result;
	int i;
	
	result = 1;
	i = -1;
	while (++i < num)
		result *= 2;
	return (result - 1);
}

void	show_hanoi(int num, char a, char b, char c)
{
	if (num == 1)
		printf("%c %c\n", a, c);
	else
	{
		show_hanoi(num - 1, a, c, b);
		printf("%c %c\n", a, c);
		show_hanoi(num - 1, b, a, c);
	}
}



int		main(void)
{
	int		num;

	scanf("%d", &num);
	getchar();  // remove the enter in the buffer

	printf("%d\n", hanoi_count(num));  // total count 
	show_hanoi(num, '1', '2', '3');  // show how to move
}
