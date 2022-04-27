/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:08:36 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "../io/ft_io.h"
#include "../string/ft_string.h"
#include <stdlib.h>

void	*ft_safe_malloc(size_t malloc_size)
{
	void *alloc = ft_calloc(malloc_size);
	if (!alloc)
		ft_exit_err("ft_safe_malloc: could not allocate %zu bytes of memory", malloc_size);
	return (alloc);
}
