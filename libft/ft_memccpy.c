/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:07:55 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/05 14:53:56 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	int	i;

	if (!dst && !src && n)
		return (NULL);
	i = -1;
	while (++i < n)
	{
		*(unsigned char *)((unsigned char *)dst + i) = *(unsigned char *)((unsigned char *)src + i);
		if (*(unsigned char *)((unsigned char *)src + i) == (unsigned char) c)
			return ((unsigned char *)dst + i + 1);
	}
	return (NULL);
}
