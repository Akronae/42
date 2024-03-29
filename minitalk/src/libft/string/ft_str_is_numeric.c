/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:22:01 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../char/ft_char.h"
#include "../logic/ft_logic.h"

int	ft_str_is_numeric(t_str s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '+' && *s != '-')
			return (false);
		s++;
	}
	return (true);
}
