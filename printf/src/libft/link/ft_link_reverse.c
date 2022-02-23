/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include "stdlib.h"

t_link	*ft_link_reverse(t_link *self)
{
	t_link	*curr;
	t_link	*last;

	curr = self->get_last(self);
	last = NULL;
	while (curr)
	{
		curr->next = curr->prev;
		curr->prev = last;
		last = curr;
		curr = curr->next;
	}
	return (self->get_first(self));
}
