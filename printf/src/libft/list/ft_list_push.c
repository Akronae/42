/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
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
