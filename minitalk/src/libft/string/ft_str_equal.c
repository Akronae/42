/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../logic/ft_logic.h"
#include <stdlib.h>

int	ft_str_equal(t_str s1, t_str s2)
{
	if (s1 == NULL)
		return (s2 == NULL);
	while (true)
	{
		if (*s1 != *s2)
			return (false );
		s1++;
		s2++;
		if (!*s1)
			return (true);
	}
}
