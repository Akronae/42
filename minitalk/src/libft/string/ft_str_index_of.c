/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_of.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../logic/ft_logic.h"
#include <unistd.h>

int	ft_str_index_of(t_string to_find, t_string in_str)
{
	size_t	in_str_i;
	size_t	to_find_i;

	in_str_i = 0;
	if (in_str == NULL || to_find == NULL)
		return (INDEX_NOT_FOUND);
	while (true)
	{
		if (to_find[0] == '\0' && in_str[in_str_i] == '\0')
			return (in_str_i);
		if (!in_str[in_str_i])
			break ;
		to_find_i = 0;
		while (in_str[in_str_i + to_find_i] == to_find[to_find_i])
		{
			to_find_i++;
			if (!to_find[to_find_i])
				return (in_str_i);
		}
		in_str_i++;
	}
	return (INDEX_NOT_FOUND);
}
