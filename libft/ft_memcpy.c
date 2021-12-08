/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:10:29 by adaubric          #+#    #+#             */
/*   Updated: 2021/12/08 14:43:53 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
	}
	return (dst);
}
