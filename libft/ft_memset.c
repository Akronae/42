/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:01:54 by adaubric          #+#    #+#             */
/*   Updated: 2022/01/05 15:05:30 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int copied_char, int len)
{
	char	*p;
	int		i;

	p = (char *)dst;
	i = -1;
	while (++i < len)
	{
		p[i] = copied_char;
	}
	return (dst);
}
