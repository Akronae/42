/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_iterator.h"
#include <stdlib.h>

t_iterator	*new_iterator(t_link *link)
{
	t_iterator	*iterator;

	iterator = malloc(sizeof(t_iterator));
	if (!iterator)
		return (NULL);
	iterator->first = link;
	iterator->current = link;
	iterator->next = &ft_iterator_next;
	iterator->next_str = &ft_iterator_next_str;
	iterator->next_char = &ft_iterator_next_char;
	iterator->reset = &ft_iterator_reset;
	iterator->free = &ft_iterator_free;
	return (iterator);
}
