//
// Created by Alexandre DAUBRICOURT on 6/30/21.
//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_4(int a, int b, int c, int d)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(' ');
	ft_putchar(c + 48);
	ft_putchar(d + 48);
}

void	print_pair(int a, int b)
{
	int	c;
	int	d;

	c = a;
	while (c <= 9)
	{
		d = b + 1;
		while (d <= 9)
		{
			print_4(a, b, c, d);
			if (a != 9 || b != 8 || c != 9 || d != 9)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			d++;
		}
		c++;
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			print_pair(a, b);
			b++;
		}
		a++;
	}
}
