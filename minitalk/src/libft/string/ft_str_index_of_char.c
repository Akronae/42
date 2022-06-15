/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_of_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../char/ft_char.h"
#include "ft_string.h"
#include <stdlib.h>

int	ft_str_index_of_char(char to_find, t_string in_str)
{
	t_string 	to_str;
	int		index;

	to_str = ft_char_to_str(to_find);
	index = ft_str_index_of(to_str, in_str);
	free(to_str);
	return (index);
}
