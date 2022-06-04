/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "../io/ft_io.h"

t_list	*ft_list_map(t_list *self, t_link *(*action)(t_link*))
{
	t_list				*mapped;
	struct t_iterator	*i;

	if (!self->first)
		return (ft_exit_err("ft_list_map: list has no first element."));
	mapped = new_list();
	i = self->get_iterator(self);
	while (i->next(i))
		mapped->push(mapped, action(i->curr));
	i->free(i);
	self->free(self);
	return (mapped);
}
