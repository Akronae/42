/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_for_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_for_each(struct t_list *self,
		void (*action)(struct t_link *elem))
{
	if (!self->first)
		return ;
	self->first->for_each(self->first, action);
}
