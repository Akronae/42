//
// Created by Alexandre DAUBRICOURT on 6/30/21.
//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	triple_print(int c, int d, int u)
{
	ft_putchar(c + 48);
	ft_putchar(d + 48);
	ft_putchar(u + 48);
}

void	print_comma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 9)
	{
		b = a + 1;
		while (b <= 9)
		{
			c = b + 1;
			while (c <= 9)
			{
				triple_print(a, b, c);
				if (a != 7 || b != 8 || c != 9)
				{
					print_comma();
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
