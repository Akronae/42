/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_set_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_link	*ft_link_set_data(t_link *self, t_type data_type, void *data)
{
	self->data_type = data_type;
	self->data = data;
	self->as_long = (long long *) data;
	self->as_str = (char *) data;
	if (self->typed_ptr)
		ft_safe_free(self->typed_ptr);
	self->typed_ptr = new_typed_ptr(data_type, data);
	return (self);
}
