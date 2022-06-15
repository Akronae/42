/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:07:52 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

t_string 	ft_strnstr(t_string big, t_string little, size_t blen)
{
	size_t	llen;

	if (*little == '\0')
		return ((t_string )big);
	llen = ft_strlen(little);
	while (*big && blen-- >= llen)
	{
		if (*big == *little && ft_strncmp(big, little, llen) == 0)
			return ((t_string )big);
		big++;
	}
	return (0);
}

#include "ft_string.h"
