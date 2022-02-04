/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:18:08 by adaubric          #+#    #+#             */
/*   Updated: 2021/12/08 18:57:00 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_at_index(void *dst, const void *src, int index)
{
	*((char *)dst + index) = *((char *)src + index);
}

void	*ft_memmove(void *dst, const void *src, int len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int) len - 1;
		while (i >= 0)
		{
			copy_at_index(dst, src, i);
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
		{
			copy_at_index(dst, src, i);
		}
	}
	return (dst);
}
