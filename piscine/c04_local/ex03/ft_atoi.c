//
// Created by Alexandre DAUBRICOURT on 7/6/21.
//
#include <unistd.h>

void	truncate_number(char *str, char *dst)
{
	int	i;

	while (str[0])
	{
		if ((str[0] >= '0' && str[0] <= '9'))
			break ;
		else
			str++;
	}
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
}

int	get_str_sign(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			count++;
		if (str[i] == ' ' && count > 0)
			return (0);
	}
	if (count % 2)
		return (-1);
	return (1);
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

int	poww(int base, int exp)
{
	int	sum;
	int	i;

	if (exp == 0)
		return (1);
	sum = base;
	i = -1;
	while (++i < exp - 1)
		sum *= base;
	return (sum);
}

int	ft_atoi(char *str)
{
	char	truncated[500];
	int		return_sign;
	int		i;
	int		sum;

	truncate_number(str, truncated);
	return_sign = get_str_sign(str);
	i = -1;
	sum = 0;
	while (truncated[++i])
	{
		sum += (truncated[i] - 48) * poww(10, ft_strlen(truncated) - i - 1);
	}
	return (return_sign * sum);
}
