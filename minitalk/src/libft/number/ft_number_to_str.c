/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"
#include "../char/ft_char.h"
#include "../logic/ft_logic.h"
#include "../list/ft_list.h"
#include "../math/ft_math.h"
#include "../string/ft_string.h"
#include "../string/ft_string.h"

t_str	ft_number_to_str(t_llong ll)
{
	t_list	*list;
	int		is_neg;
	t_str	str;

	list = new_list();
	is_neg = ll < 0;
	ll = ft_math_abs(ll);
	while (true)
	{
		list->push_str(list, ft_char_to_str(ll % 10 + '0'));
		ll /= 10;
		if (!ll)
			break ;
	}
	if (is_neg)
		list->push_str(list, ft_strdup("-"));
	list->reverse(list);
	str = list->join(list, STRING_EMPTY);
	list->free(list);
	return (str);
}
