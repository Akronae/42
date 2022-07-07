/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_past.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:12:23 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory/ft_memory.h"

t_llong	ft_str_index_past(t_str str, t_str to_find)
{
	t_llong	index;

	index = ft_str_index_of(str, to_find);
	if (index == INDEX_NOT_FOUND)
		return (index);
	return (index + ft_strlen(to_find));
}
