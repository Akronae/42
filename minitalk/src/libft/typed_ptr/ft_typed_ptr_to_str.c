/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typed_ptr_to_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_typed_ptr.h"
#include "../string/ft_string.h"
#include "../number/ft_number.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include "../char/ft_char.h"

char	*ft_typed_ptr_to_str(t_typed_ptr *self)
{
	if (self->type == T_TYPE_UNKNOWN)
		return (ft_strdup(T_TYPE_UNKNOWN_STR));
	else if (self->type == T_TYPE_STRING)
		return (ft_strdup(self->as_str));
	else if (self->type == T_TYPE_CHAR)
		return (ft_char_to_str(*self->as_str));
	else if (self->type == T_TYPE_LONG)
		return (ft_number_to_str(*self->as_long));
	else
		return (ft_exit_err(ft_strjoin("ft_list_join: cannot parse type ",
					ft_number_to_str(self->type))));
}
