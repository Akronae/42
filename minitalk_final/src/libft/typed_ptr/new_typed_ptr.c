/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_typed_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

t_typed_ptr	*new_typed_ptr(t_type type, void *value)
{
	t_typed_ptr	*ptr;

	ptr = ft_safe_malloc(sizeof(t_typed_ptr));
	ptr->type = type;
	ptr->clone = ft_typed_ptr_clone;
	ptr->free = ft_typed_ptr_free;
	ptr->set_value = ft_typed_ptr_set_value;
	ptr->to_str = ft_typed_ptr_to_str;
	ptr->value_equals = ft_typed_ptr_value_equals;
	ptr->set_value(ptr, value);
	return (ptr);
}
