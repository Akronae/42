/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_clone_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory/ft_memory.h"
#include "../string/ft_string.h"
#include "../io/ft_io.h"
#include <stdlib.h>

long long	*ft_clone_long_ptr(long long *data)
{
	long long *alloc;

	alloc = ft_safe_malloc(sizeof(long long *));
	*alloc = *data;
	return (alloc);
}


void *ft_type_clone_data(t_type data_type, void *data)
{

	if (data_type == T_TYPE_STRING)
		return (ft_strdup(data));
	if (data_type == T_TYPE_LONG)
		return (ft_clone_long_ptr((long long*)data));
	else
		return ft_exit_err("ft_type_clone_data: could not clone data type '%d'.", data_type);
}
