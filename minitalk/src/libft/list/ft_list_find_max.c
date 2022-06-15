/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../math/ft_math.h"
#include "../io/ft_io.h"

t_link	*ft_list_find_max(t_list *self, t_type of_type)
{
	t_link		*max_elem;
	t_iterator	*i;

	max_elem = NULL;
	if (self->length == 0)
		return (NULL);
	i = self->get_iterator(self);
	while (i->next(i))
	{
		if (i->curr->data->type != of_type)
			continue ;
		if (!max_elem || (of_type == T_TYPE_LLONG && *max_elem->data
				->as_llong < *i
				->curr->data->as_llong))
			max_elem = i->curr;
	}
	i->free(i);
	return (max_elem);
}
