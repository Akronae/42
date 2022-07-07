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

#include "ft_binary.h"
#include "../memory/ft_memory.h"

t_str	ft_binary_byte_to_str(char byte)
{
	size_t	i;
	t_str	binary;

	i = 0;
	binary = ft_safe_malloc(sizeof(char) * BITS_IN_BYTE + 1);
	while (i < BITS_IN_BYTE)
	{
		binary[i] = ft_binary_get_bit(byte, i) + '0';
		i++;
	}
	binary[i] = '\0';
	return (binary);
}
