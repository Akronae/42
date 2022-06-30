/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_value_pair_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:44:06 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:22:17 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_value_pair.h"
#include "../memory/ft_memory.h"
#include "../io/ft_io.h"
#include <stdlib.h>

void	ft_key_value_pair_free(t_key_value_pair *self)
{
//	ft_printfl("freeing key %s", self->key->to_str(self->key));
	self->key->free(self->key);
//	ft_printfl("freeing val %s", self->value->to_str(self->value));
	self->value->free(self->value);
	ft_safe_free(self);
}
