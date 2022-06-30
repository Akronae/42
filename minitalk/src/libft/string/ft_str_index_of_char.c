/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_index_of_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../char/ft_char.h"
#include "../memory/ft_memory.h"
#include "ft_string.h"
#include <stdlib.h>
#include "../libft.h"

llong	ft_str_index_of_char(t_str str, char to_find)
{
	t_str 	to_str;
	llong		index;

	to_str = ft_char_to_str(to_find);
	index = ft_str_index_of(str, to_str);
	ft_safe_free(to_str);
	return (index);
}
