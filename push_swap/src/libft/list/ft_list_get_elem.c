/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../io/ft_io.h"

t_link	*ft_list_get_elem(t_list *self, long at_index)
{
	long	i;
	t_link	*elem;

	if (at_index < 0)
		at_index += self->length;
	ft_check_index_out_of_range_error("ft_list_get_elem", at_index,
		self->length);
	i = 0;
	elem = self->first;
	while (i < at_index)
	{
		elem = elem->next;
		i++;
	}
	return (elem);
}
