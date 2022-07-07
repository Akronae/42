/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_typed_ptr_llong.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"

t_typed_ptr	*new_typed_ptr_llong(t_llong decimal)
{
	t_llong	*ptr;

	ptr = ft_safe_malloc(sizeof(t_llong));
	*ptr = decimal;
	return (new_typed_ptr(T_TYPE_LLONG, ptr));
}

t_typed_ptr	*ft_lld(t_llong decimal)
{
	return (new_typed_ptr_llong(decimal));
}
