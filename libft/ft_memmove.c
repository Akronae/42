/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:18:08 by adaubric          #+#    #+#             */
/*   Updated: 2021/12/08 18:16:52 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	int	i;
	int offset;


	i = -1;
	if (dst > src)
	{
		offset = 1;
	}
	else offset = 0;
	while (++i < len)
	{
		*(char *)(dst + i + (offset * (len - 1 - i))) = *(char *)(src + i);
	}
	return (dst);
}
