/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_typed_ptr_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include "../string/ft_string.h"
#include <stdlib.h>

t_typed_ptr	*new_typed_ptr_decimal(long long decimal)
{
	long long	*ptr;

	ptr = ft_safe_malloc(sizeof(long long));
	*ptr = decimal;
	return (new_typed_ptr(T_TYPE_LONG, ptr));
}

t_typed_ptr	*ft_d(long long decimal)
{
	return (new_typed_ptr_decimal(decimal));
}
