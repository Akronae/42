/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_str_from_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list/ft_list.h"
#include "../char/ft_char.h"
#include "../logic/ft_logic.h"
#include "../number/ft_number.h"
#include "../string/ft_string.h"

t_str	ft_hex_str_from_nbr(t_ullong ull)
{
	t_list	*list;
	t_str	str;

	list = new_list();
	while (true)
	{
		list->push_str(list, ft_char_to_str(BASE_HEX[ull % 16]));
		ull /= 16;
		if (!ull)
			break ;
	}
	list->reverse(list);
	str = list->join(list, STRING_EMPTY);
	list->free(list);
	return (str);
}
