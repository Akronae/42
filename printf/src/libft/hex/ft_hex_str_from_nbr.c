/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_str_from_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list/ft_list.h"
#include "../char/ft_char.h"
#include "../boolean/ft_boolean.h"

char	*ft_hex_str_from_nbr(unsigned long long ull)
{
	char	*base;
	t_list	*list;
	char	*str;

	base = "0123456789abcdef";
	list = new_list();
	while (TRUE)
	{
		list->push_str(list, ft_char_to_str(base[ull % 16]));
		ull /= 16;
		if (!ull)
			break ;
	}
	list->reverse(list);
	str = list->join(list, "");
	list->free(list);
	return (str);
}
