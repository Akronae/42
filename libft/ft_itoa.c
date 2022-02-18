/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:00:30 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/13 12:07:26 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_abs(int n)
{
	if (n < 0)
		return (n * -1L);
	return (n);
}

static int	ft_pow(int base, int exp)
{
	int	n;

	n = base;
	if (exp == 0)
		return (1);
	while (exp > 1)
	{
		n *= base;
		exp -= 1;
	}
	return (n);
}

static int	ft_count_digits(int n)
{
	size_t	num;
	int		count;

	num = ft_abs(n);
	count = 0;
	if (n == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	num;
	int		digits_count;
	char	*str;
	int		str_i;

	num = ft_abs(n);
	digits_count = ft_count_digits(num);
	str = malloc(sizeof(char)
			* (digits_count + (ft_abs(n) != (unsigned long)n) + 1));
	if (!str)
		return (NULL);
	str_i = -1;
	if (n < 0)
		str[++str_i] = '-';
	while (digits_count > 0)
	{
		str[++str_i] = (num / (ft_pow(10, --digits_count))) % 10 + '0';
	}
	str[++str_i] = '\0';
	return (str);
}
