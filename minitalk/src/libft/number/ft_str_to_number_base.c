/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_number_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"
#include "../char/ft_char.h"
#include "../string/ft_string.h"

long long	ft_str_to_number_base(t_string s, t_string base)
{
	size_t		i;
	long long	nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			nbr = nbr * ft_strlen(base) + ft_str_index_of_char(s[i], base);
		else if (nbr > 0)
			break ;
		else if (s[i] == '+')
			sign = 1;
		else if (s[i] == '-')
			sign = -1;
		s++;
	}
	return (sign * nbr);
}
