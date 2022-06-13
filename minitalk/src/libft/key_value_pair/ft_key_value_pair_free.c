/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_value_pair_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_value_pair.h"
#include "../memory/ft_memory.h"
#include <stdlib.h>

void	ft_key_value_pair_free(t_key_value_pair *self)
{
	self->key->free(self->key);
	self->value->free(self->value);
	ft_safe_free(self);
}
