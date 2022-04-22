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
#include <stdlib.h>

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
			free(temp->data);
		free(temp);
	}
}
