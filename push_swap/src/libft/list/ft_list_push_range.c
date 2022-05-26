/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_range.c                                     :+:      :+:    :+:   */
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
#include <unistd.h>

t_list 	*ft_list_push_range(t_list *self, t_list *to_push, long from, long to)
{
	t_iterator	*i;

	if (to_push->length == 0)
		return (self);
	if (from < 0)
		from = to_push->length + from + 1;
	if (to < 0)
		to = to_push->length + to + 1;
	ft_check_index_out_of_range_error("ft_list_push_range", from, to_push->length + 1);
	ft_check_index_out_of_range_error("ft_list_push_range", to, to_push->length + 1); // max 'to' can be bigger than array max index as 'to' is exclusive
	i = to_push->get_iterator(to_push);
	i->skip(i, (size_t) from);
	while (i->next(i) && i->index < to)
	{
		self->push(self, i->curr->clone(i->curr));
	}
	i->free(i);
	return (self);
}
