/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_clone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_typed_ptr.h"
#include "../memory/ft_memory.h"
#include "../string/ft_string.h"
#include "../io/ft_io.h"
#include <stdlib.h>

t_typed_ptr	*ft_typed_ptr_clone(t_typed_ptr *self)
{
	if (self->type == T_TYPE_STRING)
		return (new_typed_ptr_str(ft_strdup(self->value)));
	if (self->type == T_TYPE_LLONG)
		return (new_typed_ptr_llong(*self->as_llong));
	else
		return (ft_exit_err("ft_typed_ptr_clone: "
				"could not clone data type '%d'.", self->type));
}
