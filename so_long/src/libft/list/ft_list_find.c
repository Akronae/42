/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
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
	t_link		*found;
	t_iterator	*i;

	found = NULL;
	i = self->get_iterator(self);
	while (i->next(i))
	{
		if (find_data->value_equals(find_data, i->curr->data))
		{
			found = (i->curr);
			break ;
		}
	}
	i->free(i);
	return (found);
}
