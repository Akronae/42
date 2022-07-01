/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kv_pair.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaubric <adaubric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:34:59 by adaubric          #+#    #+#             */
/*   Updated: 2022/02/23 14:02:10 by adaubric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_KV_PAIR_H
# define FT_KV_PAIR_H

# include "unistd.h"
# include "../typed_ptr/ft_typed_ptr.h"
# include "../type/ft_type.h"

typedef struct t_kv_pair
{
	t_typed_ptr	*key;
	t_typed_ptr	*value;
	void		(*free)(struct t_kv_pair *self);
}	t_kv_pair;

void		ft_kv_pair_free(t_kv_pair *self);
t_kv_pair	*new_kv_pair(t_typed_ptr *key, t_typed_ptr *value);

#endif
