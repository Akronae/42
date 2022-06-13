/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_link_free(t_link *self)
{
	t_link	*temp;
	t_link	*elem;

	elem = self->get_first(self);
	while (elem)
	{
		temp = elem;
		elem = elem->next;
		if (temp->data)
			temp->data->free(temp->data);
		ft_safe_free(temp);
	}
}
