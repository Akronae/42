/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_by_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../io/ft_io.h"

t_link	*ft_list_remove_by_data(t_list *self, t_typed_ptr *data)
{
	t_link		*removed;
	t_iterator	*i;

	removed = NULL;
	i = self->get_iterator(self);
	while (i->next(i))
	{
		if (i->curr->data->type == data->type
			&& i->curr->data->value == data->value)
		{
			removed = self->remove_at(self, i->index);
			break ;
		}
	}
	i->free(i);
	return (removed);
}
