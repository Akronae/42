/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_maxes.c                                :+:      :+:    :+:   */
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

t_list	*ft_list_find_maxes(t_list *self, t_type of_type, size_t count)
{
	t_list	*self_cloned;
	t_list	*maxes;
	size_t	i;

	maxes = new_list();
	if (self->length == 0)
		return (maxes);
	self_cloned = self->clone(self);
	i = 0;
	while (i < count && self_cloned->length > 0)
	{
		maxes->push(maxes, self_cloned->remove_by_data(self_cloned, self_cloned->find_max(self_cloned, of_type)->data));
		i++;
	}
	self_cloned->free(self_cloned);
    return (maxes);
}
