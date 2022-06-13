/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_for_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_link.h"
#include "stdlib.h"

void	ft_link_for_each(struct t_link *self,
		void (*action)(struct t_link *elem))
{
	t_link	*curr;

	curr = self->get_first(self);
	while (curr)
	{
		action(curr);
		curr = curr->next;
	}
}
