/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:01:54 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/17 15:14:18 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <unistd.h>

void	*ft_memset(void *dst, int copied_char, size_t len)
{
	char	*p;
	size_t	i;

	p = (char *)dst;
	i = 0;
	while (i < len)
	{
		p[i] = copied_char;
		i++;
	}
	return (dst);
}
