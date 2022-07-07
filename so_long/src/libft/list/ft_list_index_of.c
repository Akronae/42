/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_index_of.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "../libft.h"

long	ft_list_index_of(t_list *self, t_link *elem)
{
	t_iterator	*i;
	long		index;

	index = INDEX_NOT_FOUND;
	i = self->get_iterator(self);
	while (i->next(i))
	{
		if (i->curr == elem)
		{
			index = (i->index);
			break ;
		}
	}
	i->free(i);
	return (index);
}
