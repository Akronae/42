//
// Created by Alexandre DAUBRICOURT on 7/6/21.
//
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_invalid_char(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

int	check_base(char *str)
{
	char	*c;
	int		i;
	int		j;

	c = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (0);
	while (*c)
	{
		if (is_invalid_char(*c) || *c == '+' || *c == '-')
			return (0);
		c++;
	}
	i = 0;
	while (i < c - str)
	{
		j = i + 1;
		while (j < c - str)
			if (str[i] == str[j++])
				return (0);
		i++;
	}
	return (1);
}

int	index_of_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	return_sign;
	int	matched;
	int	result;

	if (!check_base(base))
		return (0);
	while (is_invalid_char(*str))
		str++;
	return_sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return_sign *= -1;
		str++;
	}
	result = 0;
	while (1)
	{
		matched = index_of_char(base, str[0]);
		if (matched == -1)
			break ;
		result = result * ft_strlen(base) + matched;
		str++;
	}
	return (result * return_sign);
}
