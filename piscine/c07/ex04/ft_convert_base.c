//
// Created by Alexandre DAUBRICOURT on 7/13/21.
//
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);
int	check_base(char *str);

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_power(nb, power - 1));
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	place_digit(int *nb, char *str, char *base, int digit_rank)
{
	int	base_idx;
	int	dig_dec;

	base_idx = ft_strlen(base);
	while (--base_idx >= 0)
	{
		dig_dec = base_idx * ft_power(ft_strlen(base), digit_rank);
		if (dig_dec <= *nb)
			break ;
	}
	*nb -= dig_dec;
	str[ft_strlen(str)] = base[base_idx];
}

char	*ft_itoa_base(int nb, char *base)
{
	char	*str;
	int		digit_count;

	digit_count = 0;
	while (ft_power(ft_strlen(base), ++digit_count) <= abs(nb))
		;
	str = malloc(sizeof(char) * (digit_count + 2));
	if (nb < 0)
	{
		str[ft_strlen(str)] = '-';
	}
	nb = abs(nb);
	while (digit_count-- > 0)
	{
		place_digit(&nb, str, base, digit_count);
	}
	str[ft_strlen(str)] = 0;
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_decimal;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	nbr_decimal = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(nbr_decimal, base_to));
}
