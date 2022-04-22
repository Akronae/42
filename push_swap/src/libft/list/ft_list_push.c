/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

t_link	*ft_list_push(t_list *self, t_link *to_push)
{
	if (!self->first_element)
	{
		self->first_element = to_push;
		self->last_element = self->first_element;
	}
	else
		self->last_element = self->last_element->insert(self->last_element, to_push);
	self->length += 1;
	return (to_push);
}
