/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_get_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../logic/ft_logic.h"

t_bool	ft_binary_get_bit(char byte, int index)
{
	return ((byte & (1 << index)) != false);
}
