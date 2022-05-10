/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                 :+:      :+:    :+:   */
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

t_list	*ft_list_sort(t_list *self, t_type of_type)
{
	t_list *sorted;
	t_iterator	*i;

	sorted = self->clone(self);
	i = sorted->get_iterator(sorted);
	while (i->next(i))
	{
		if (i->curr->data_type != of_type)
			continue;
		if (of_type == T_TYPE_LONG)
		{
			if (i->curr->prev == NULL || *i->curr->as_long > *i->curr->prev->as_long)
				continue;
			sorted->swap(sorted, i->index, i->index - 1);
			i->reset(i);
		}
	}
	i->free(i);
    return (sorted);
}