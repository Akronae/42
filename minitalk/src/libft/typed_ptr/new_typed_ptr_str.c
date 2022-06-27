/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_typed_ptr_str.c                                :+:      :+:    :+:   */
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

t_typed_ptr	*new_typed_ptr_str(t_str value)
{
	return (new_typed_ptr(T_TYPE_STRING, value));
}

t_typed_ptr	*ft_s(t_str str)
{
	return (new_typed_ptr_str(ft_strdup(str)));
}
