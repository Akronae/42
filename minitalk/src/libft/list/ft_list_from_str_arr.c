/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_for_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:09:59 by adaubric          #+#    #+#       	  */
/*   Updated: 2022/02/21 14:58:44 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"
#include "../string/ft_string.h"
#include "../io/ft_io.h"

t_list	*ft_list_from_str_arr(struct t_list *self, char **arr, size_t from,
	size_t to)
{
	size_t	i;

	i = from;
	while (i < to)
	{
		self->push_str(self, ft_strdup(arr[i]));
		i++;
	}
	return (self);
}
