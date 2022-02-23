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

void	*ft_list_push(t_list *self)
{
	if (!self->first_element)
	{
		self->first_element = new_link();
		if (!self->first_element)
			return (NULL);
		self->last_element = self->first_element;
	}
	else
		self->last_element = self->last_element->insert(self->last_element);
	self->length += 1;
	return (self->last_element);
}
