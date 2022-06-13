/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_list.h"
#include "../math/ft_math.h"
#include "../io/ft_io.h"

size_t	ft_list_count(t_list *self, t_typed_ptr *value)
{
	size_t		count;
	t_iterator	*i;

	count = 0;
	i = self->get_iterator(self);
	while (i->next(i))
	{
		if (i->curr->data->value_equals(i->curr->data, value))
			count++;
	}
	i->free(i);
	return (count);
}
