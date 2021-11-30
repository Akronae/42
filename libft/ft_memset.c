/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:01:54 by adaubric          #+#    #+#             */
/*   Updated: 2021/11/28 17:05:38 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int copied_char, size_t len)
{
	char	*p;

	p = (char *)dst;
	while (len > 0)
	{
		p[len - 1] = copied_char;
		len--;
	}
	return (dst);
}