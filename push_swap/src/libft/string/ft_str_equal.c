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

#include "../boolean/ft_boolean.h"
#include <stdlib.h>

int	ft_str_equal(char *s1, char *s2)
{
	if (s1 == NULL)
		return (s2 == NULL);
	while (TRUE)
	{
		if (*s1 != *s2)
			return (FALSE);
		s1++;
		s2++;
		if (!*s1)
			return (TRUE);
	}
}
