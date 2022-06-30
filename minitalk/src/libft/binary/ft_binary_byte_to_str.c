/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_byte_to_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "../logic/ft_logic.h"
#include "../memory/ft_memory.h"

t_str ft_binary_byte_to_str(char byte)
{
	size_t i = 0;
	t_str binary = ft_safe_malloc(sizeof(char) * 8 + 1);
	while (i < 8)
	{
		binary[i] = ((byte & (1 << i)) != false) + '0';
		i++;
	}
	binary[i] = '\0';
	return (binary);
}
