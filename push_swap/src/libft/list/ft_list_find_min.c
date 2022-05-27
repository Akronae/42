/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_min.c                                 :+:      :+:    :+:   */
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

t_link	*ft_list_find_min(t_list *self, t_type of_type)
{
	t_link	*min_elem;
	t_iterator	*i;

	min_elem = NULL;
	if (self->length == 0)
		return (NULL);
	i = self->get_iterator(self);
	while (i->next(i))
	{
		if (i->curr->data->type != of_type)
			continue;
		if (!min_elem || (of_type == T_TYPE_LONG && *min_elem->data->as_long > *i->curr->data->as_long))
			min_elem = i->curr;
	}
	i->free(i);
    return (min_elem);
}
