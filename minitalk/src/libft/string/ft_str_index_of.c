/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../logic/ft_logic.h"
#include <unistd.h>

t_llong	ft_str_index_of(t_str str, t_str to_find)
{
	size_t	str_i;
	size_t	to_find_i;

	str_i = 0;
	if (str == NULL || to_find == NULL)
		return (INDEX_NOT_FOUND);
	while (true)
	{
		if (to_find[0] == '\0' && str[str_i] == '\0')
			return (str_i);
		if (!str[str_i])
			break ;
		to_find_i = 0;
		while (str[str_i + to_find_i] == to_find[to_find_i])
		{
			to_find_i++;
			if (!to_find[to_find_i])
				return (str_i);
		}
		str_i++;
	}
	return (INDEX_NOT_FOUND);
}
