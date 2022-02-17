/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:07:52 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 15:14:18 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t blen)
{
	size_t	llen;

	if (*little == '\0')
		return ((char *)big);
	llen = ft_strlen(little);
	while (*big && blen-- >= llen)
	{
		if (*big == *little && ft_strncmp(big, little, llen) == 0)
			return ((char *)big);
		big++;
	}
	return (0);
}
