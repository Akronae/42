#include <unistd.h>
#include "ex08/ft_sort_int_tab.c"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(-(nb % 10));
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + 48);
}

int main()
{
	int a = 434;
	int b = 88;
	int c;
	int d;
	int e[] = {584, 1, -4, 2, 4565654};

	ft_sort_int_tab(&e, 5);
	ft_putnbr(a);
	ft_putchar('\n');
	ft_putnbr(b);
	ft_putchar('\n');
	ft_putnbr(c);
	ft_putchar('\n');
	ft_putnbr(d);
	ft_putchar('\n');
	return 0;
}
