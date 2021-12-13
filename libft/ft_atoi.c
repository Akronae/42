/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:50:17 by adaubric          #+#    #+#             */
/*   Updated: 2021/12/13 15:03:15 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	unsigned int	res;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		   str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i] == '-') sign = -1;
		else if (str[i] == '+') sign = 1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}
