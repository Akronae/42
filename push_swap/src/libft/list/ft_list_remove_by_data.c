/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_by_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_link	*ft_list_remove_by_data(t_list *self, void *data)
{
	t_iterator	*i;

	i = self->get_iterator(self);
	while (i->next)
	{
		if (i->curr->data == data)
			return self->remove_at(self, i->index);
	}
	i->free(i);
	return (NULL);
}
