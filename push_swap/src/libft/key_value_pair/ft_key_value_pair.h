/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_value_pair.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KEY_VALUE_PAIR_H
# define FT_KEY_VALUE_PAIR_H

# include "unistd.h"
# include "../type/ft_type.h"
# include "../typed_ptr/ft_typed_ptr.h"

typedef struct t_key_value_pair
{
	t_typed_ptr	*key;
	t_typed_ptr	*value;
	void 	(*free)(struct t_key_value_pair *self);
}	t_key_value_pair;

void				ft_key_value_pair_free(t_key_value_pair *self);
t_key_value_pair	*new_key_value_pair(t_typed_ptr *key, t_typed_ptr *value);

#endif
