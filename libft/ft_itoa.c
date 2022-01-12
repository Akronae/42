/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:00:30 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/12 12:57:07 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int ft_pow(int base, int exp)
{
	int n;

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
	int count;

	count = 0;
	n = ft_abs(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int	digits_count;
	char	*str = malloc(12);
	int 	str_i;

	digits_count = ft_count_digits(n);
	str_i = -1;
	if (n < 0)
		str[++str_i] = '-';
	n = ft_abs(n);
	while (digits_count >= 0)
	{
		str[++str_i] = (n / (ft_pow(10, --digits_count))) % 10 + '0';
	}
	str[++str_i] = '\0';

	return (str);
}
