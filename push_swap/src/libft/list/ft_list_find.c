/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../typed_ptr/ft_typed_ptr.h"
#include "../ptr/ft_ptr.h"
#include "../memory/ft_memory.h"

t_link	*ft_list_find(t_list *self, t_typed_ptr *find_data)
{
	t_iterator	*i;
	t_typed_ptr *typed;

	typed = NULL;
	i = self->get_iterator(self);
	while (i->next)
	{
		if (i->curr->data_type != find_data->type)
			continue;
		if (typed)
			typed->free(typed);
		typed = new_typed_ptr(i->curr->data_type, i->curr->data);
		if (find_data->value_equals(find_data, typed))
			return (i->curr);
	}
	if (typed)
		typed->free(typed);
	i->free(i);
	find_data->free(find_data);
	return (NULL);
}
