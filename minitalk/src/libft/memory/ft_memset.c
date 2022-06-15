/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:01:54 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <unistd.h>

void	*ft_memset(void *dst, int copied_char, size_t len)
{
	t_string 	p;
	size_t	i;

	p = (t_string )dst;
	i = 0;
	while (i < len)
	{
		p[i] = copied_char;
		i++;
	}
	return (dst);
}
