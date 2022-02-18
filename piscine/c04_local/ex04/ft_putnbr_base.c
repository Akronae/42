//
// Created by Alexandre DAUBRICOURT on 7/6/21.
//
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

int	number_of_char(char *str, char sub)
{
	int	sum;

	sum = 0;
	while (str[0])
	{
		if (str[0] == sub)
			sum++;
		str++;
	}
	return (sum);
}

int	is_base_valid(char *base)
{
	int	i;

	if (ft_strlen(base) <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| base[i] < 32 || base[i] > 126
			|| number_of_char(base, base[i]) > 1)
			return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!is_base_valid(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base);
		return ;
	}
	if (nbr > ft_strlen(base) - 1)
	{
		ft_putnbr_base(nbr / ft_strlen(base), base);
	}
	ft_putchar(base[(nbr % ft_strlen(base))]);
}
